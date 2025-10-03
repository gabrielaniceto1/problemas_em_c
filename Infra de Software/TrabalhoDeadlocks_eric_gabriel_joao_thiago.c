// barbearia.c
// Linux/macOS:  gcc -O2 -pthread -o barbearia barbearia.c
// MinGW (Windows): gcc -O2 -pthread -o barbearia.exe barbearia.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#include <time.h>
#include <stdarg.h>   // <-- faltava
#ifdef _WIN32
  #include <windows.h>
  static void sleep_sec(int s){ Sleep(s*1000); }
#else
  #include <unistd.h>
  static void sleep_sec(int s){ sleep(s); }
#endif

// =========================
// Util
// =========================
static int rand_range(int a, int b) { // [a,b]
    return a + rand() % (b - a + 1);
}

typedef struct Cliente Cliente;
typedef struct Barbeiro Barbeiro;

// =========================
// Pessoa / Cliente / Barbeiro
// =========================
typedef struct {
    int id;
} Pessoa;

struct Cliente {
    Pessoa p;
    pthread_t th;

    // monitor por-cliente (para acordar o cliente certo)
    pthread_mutex_t m;
    pthread_cond_t  cond_start; // barbeiro chama quando o corte vai iniciar
    pthread_cond_t  cond_end;   // barbeiro sinaliza término do corte
    pthread_cond_t  cond_left;  // cliente sinaliza que levantou e saiu

    // estado interno
    bool assigned;          // foi designado a um barbeiro?
    bool haircut_done;      // corte terminou
    bool left_chair;        // cliente levantou da cadeira
    int  barber_id;         // barbeiro que o atendeu (para logs)
};

struct Barbeiro {
    Pessoa p;
    pthread_t th;

    // estado no monitor global
    Cliente *current_client; // cliente sendo atendido
};

// =========================
// Barbearia (Monitor Global)
// =========================
typedef struct {
    // parâmetros
    int n_barbers;
    int m_wait_seats;

    // fila FIFO de espera (capacidade m_wait_seats)
    Cliente **queue;
    int q_cap;
    int q_head;
    int q_tail;
    int q_size;

    // barbeiros
    Barbeiro *barbers;

    // fila de barbeiros ociosos
    Barbeiro **idle_barbers;
    int idle_head, idle_tail, idle_size, idle_cap;

    // sincronização global
    pthread_mutex_t m;
    pthread_cond_t  cond_customers; // barbeiros esperam clientes chegarem

    // métricas
    int total_clients; // número de threads clientes
    bool running;
} Barbearia;

static Barbearia shop;

// =========================
// Fila circular de clientes (espera)
// =========================
static void q_init(Barbearia *s, int cap) {
    s->queue = (Cliente**)calloc((cap>0?cap:1), sizeof(Cliente*));
    s->q_cap = cap;
    s->q_head = s->q_tail = s->q_size = 0;
}
static bool q_push(Barbearia *s, Cliente *c) {
    if (s->q_cap == 0) return false;
    if (s->q_size == s->q_cap) return false;
    s->queue[s->q_tail] = c;
    s->q_tail = (s->q_tail + 1) % s->q_cap;
    s->q_size++;
    return true;
}
static Cliente* q_pop(Barbearia *s) {
    if (s->q_size == 0) return NULL;
    Cliente *c = s->queue[s->q_head];
    s->q_head = (s->q_head + 1) % s->q_cap;
    s->q_size--;
    return c;
}

// =========================
// Fila de barbeiros ociosos
// =========================
static void idle_init(Barbearia *s, int cap) {
    s->idle_barbers = (Barbeiro**)calloc((cap>0?cap:1), sizeof(Barbeiro*));
    s->idle_cap = cap;
    s->idle_head = s->idle_tail = s->idle_size = 0;
}
static bool idle_push(Barbearia *s, Barbeiro *b) {
    if (s->idle_size == s->idle_cap) return false;
    s->idle_barbers[s->idle_tail] = b;
    s->idle_tail = (s->idle_tail + 1) % s->idle_cap;
    s->idle_size++;
    return true;
}
static Barbeiro* idle_pop(Barbearia *s) {
    if (s->idle_size == 0) return NULL;
    Barbeiro *b = s->idle_barbers[s->idle_head];
    s->idle_head = (s->idle_head + 1) % s->idle_cap;
    s->idle_size--;
    return b;
}

// =========================
// Logs thread-safe
// =========================
static pthread_mutex_t log_m = PTHREAD_MUTEX_INITIALIZER;
static void logf(const char *fmt, ...) {
    pthread_mutex_lock(&log_m);
    va_list ap; va_start(ap, fmt);
    vfprintf(stdout, fmt, ap);
    fprintf(stdout, "\n");
    fflush(stdout);
    va_end(ap);
    pthread_mutex_unlock(&log_m);
}

// =========================
// Assinaturas
// =========================
static bool cortaCabelo(Cliente *c);           // operação do cliente
static Cliente* proximoCliente(Barbeiro *b);   // operação do barbeiro
static void corteTerminado(Barbeiro *b, Cliente *c);

// =========================
// Implementação das operações pedidas
// =========================
static bool cortaCabelo(Cliente *c) {
    // reset estado por chamada
    pthread_mutex_lock(&c->m);
    c->assigned = false;
    c->haircut_done = false;
    c->left_chair = false;
    c->barber_id = -1;
    pthread_mutex_unlock(&c->m);

    pthread_mutex_lock(&shop.m);

    // 1) Se há barbeiro ocioso, cliente vai direto
    Barbeiro *idle = idle_pop(&shop);
    if (idle != NULL) {
        idle->current_client = c;
        pthread_mutex_lock(&c->m);
        c->assigned = true;
        c->barber_id = idle->p.id;
        pthread_mutex_unlock(&c->m);

        logf("Cliente %d cortando cabelo com Barbeiro %d", c->p.id, idle->p.id);
        pthread_cond_broadcast(&shop.cond_customers);

        pthread_mutex_unlock(&shop.m);

        pthread_mutex_lock(&c->m);
        // já está assigned; apenas segue
        pthread_mutex_unlock(&c->m);
    } else {
        // 2) Não há barbeiro livre -> tenta sentar na fila
        if (shop.q_cap == 0 || shop.q_size == shop.q_cap) {
            pthread_mutex_unlock(&shop.m);
            logf("Cliente %d tentou entrar na barbearia, mas está lotada... indo dar uma voltinha", c->p.id);
            return false;
        }
        q_push(&shop, c);
        logf("Cliente %d esperando corte...", c->p.id);
        pthread_cond_broadcast(&shop.cond_customers);
        pthread_mutex_unlock(&shop.m);

        // aguarda ser chamado (cond_start)
        pthread_mutex_lock(&c->m);
        while (!c->assigned) {
            pthread_cond_wait(&c->cond_start, &c->m);
        }
        pthread_mutex_unlock(&c->m);
    }

    // agora aguarda término do corte
    pthread_mutex_lock(&c->m);
    while (!c->haircut_done) {
        pthread_cond_wait(&c->cond_end, &c->m);
    }
    pthread_mutex_unlock(&c->m);

    // sinaliza que levantou e saiu
    logf("Cliente %d terminou o corte... saindo da barbearia!", c->p.id);
    pthread_mutex_lock(&c->m);
    c->left_chair = true;
    pthread_cond_signal(&c->cond_left);
    pthread_mutex_unlock(&c->m);

    return true;
}

static Cliente* proximoCliente(Barbeiro *b) {
    pthread_mutex_lock(&shop.m);

    if (b->current_client == NULL && shop.q_size == 0) {
        idle_push(&shop, b);
        logf("Barbeiro %d indo dormir um pouco... não há clientes na barbearia...", b->p.id);
        do {
            pthread_cond_wait(&shop.cond_customers, &shop.m);
        } while (b->current_client == NULL && shop.q_size == 0);
        logf("Barbeiro %d acordou! Começando os trabalhos!", b->p.id);
    }

    Cliente *c = NULL;
    if (shop.q_size > 0) {
        c = q_pop(&shop);
        b->current_client = c;
    } else if (b->current_client != NULL) {
        c = b->current_client;
    }

    if (c) {
        pthread_mutex_lock(&c->m);
        c->assigned = true;
        c->barber_id = b->p.id;
        pthread_mutex_unlock(&c->m);
        logf("Cliente %d cortando cabelo com Barbeiro %d", c->p.id, b->p.id);
        pthread_cond_signal(&c->cond_start);
    }

    pthread_mutex_unlock(&shop.m);
    return c;
}

static void corteTerminado(Barbeiro *b, Cliente *c) {
    pthread_mutex_lock(&c->m);
    c->haircut_done = true;
    pthread_cond_signal(&c->cond_end);
    while (!c->left_chair) {
        pthread_cond_wait(&c->cond_left, &c->m);
    }
    pthread_mutex_unlock(&c->m);

    pthread_mutex_lock(&shop.m);
    b->current_client = NULL;
    pthread_mutex_unlock(&shop.m);
}

// =========================
// Threads
// =========================
static void* thread_barbeiro(void *arg) {
    Barbeiro *b = (Barbeiro*)arg;
    while (shop.running) {
        sleep_sec(rand_range(1,3));
        Cliente *c = proximoCliente(b);
        if (!c) continue;
        sleep_sec(rand_range(1,3)); // tempo de corte
        corteTerminado(b, c);
    }
    return NULL;
}

static void* thread_cliente(void *arg) {
    Cliente *c = (Cliente*)arg;
    while (shop.running) {
        (void)cortaCabelo(c);
        sleep_sec(rand_range(3,5)); // volta depois
    }
    return NULL;
}

// =========================
static void cliente_init(Cliente *c, int id) {
    c->p.id = id;
    pthread_mutex_init(&c->m, NULL);
    pthread_cond_init(&c->cond_start, NULL);
    pthread_cond_init(&c->cond_end, NULL);
    pthread_cond_init(&c->cond_left, NULL);
    c->assigned = false;
    c->haircut_done = false;
    c->left_chair = false;
    c->barber_id = -1;
}

static void barbeiro_init(Barbeiro *b, int id) {
    b->p.id = id;
    b->current_client = NULL;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <n_barbeiros> <m_assentos_espera> <total_clientes>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int tc = atoi(argv[3]);
    if (n <= 0 || m < 0 || tc <= 0) {
        fprintf(stderr, "Parâmetros inválidos.\n");
        return 1;
    }

    srand((unsigned)time(NULL));

    // init barbearia
    shop.n_barbers = n;
    shop.m_wait_seats = m;
    q_init(&shop, m);
    idle_init(&shop, n);
    pthread_mutex_init(&shop.m, NULL);
    pthread_cond_init(&shop.cond_customers, NULL);
    shop.total_clients = tc;
    shop.running = true;

    // criar barbeiros
    shop.barbers = (Barbeiro*)calloc(n, sizeof(Barbeiro));
    for (int i = 0; i < n; ++i) {
        barbeiro_init(&shop.barbers[i], i+1);
        pthread_create(&shop.barbers[i].th, NULL, thread_barbeiro, &shop.barbers[i]);
    }

    // criar clientes
    Cliente *clientes = (Cliente*)calloc(tc, sizeof(Cliente));
    for (int i = 0; i < tc; ++i) {
        cliente_init(&clientes[i], i+1);
        pthread_create(&clientes[i].th, NULL, thread_cliente, &clientes[i]);
    }

    // Mantém rodando "para sempre"; troque por um tempo fixo se quiser.
    while (1) {
        sleep_sec(60);
    }

    return 0;
}
