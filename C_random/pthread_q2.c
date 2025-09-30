// prodcons.c
// Problema do Produtor/Consumidor com pthreads + variáveis de condição (POSIX)
// - Buffer circular limitado
// - Múltiplos produtores e consumidores
// - Espera condicional com while (para evitar wake-ups espúrios)

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>   // sleep/usleep

// ---------------------- Parâmetros ajustáveis ----------------------
#define BUFFER_SIZE         8     // tamanho do buffer circular
#define NUM_PRODUCERS       2     // quantos produtores
#define NUM_CONSUMERS       3     // quantos consumidores
#define ITEMS_PER_PRODUCER  20    // cada produtor produzirá N itens

// Para deixar a saída mais "humana"
#define MIN_USLEEP_PROD  100000    // 10ms
#define MAX_USLEEP_PROD  800000    // 80ms
#define MIN_USLEEP_CONS  200000    // 20ms
#define MAX_USLEEP_CONS 1200000    // 120ms
// -------------------------------------------------------------------

// Buffer circular e seus metadados
typedef struct {
    int data[BUFFER_SIZE];
    int head;   // posição do próximo a ser removido
    int tail;   // posição onde inserir próximo item
    int count;  // quantos itens válidos no buffer

    pthread_mutex_t mtx;      // protege todas as variáveis acima
    pthread_cond_t  not_full; // sinaliza que há espaço para produzir
    pthread_cond_t  not_empty;// sinaliza que há item para consumir
} bounded_buffer_t;

// Pacote de argumentos para threads
typedef struct {
    int id;
    bounded_buffer_t* buf;
} thread_arg_t;

// ---------------------- Utilidades ----------------------
static int rnd_between(int a, int b) { // [a, b]
    return a + rand() % (b - a + 1);
}

static void buffer_init(bounded_buffer_t* b) {
    b->head = b->tail = b->count = 0;
    pthread_mutex_init(&b->mtx, NULL);
    pthread_cond_init(&b->not_full, NULL);
    pthread_cond_init(&b->not_empty, NULL);
}

static void buffer_destroy(bounded_buffer_t* b) {
    pthread_mutex_destroy(&b->mtx);
    pthread_cond_destroy(&b->not_full);
    pthread_cond_destroy(&b->not_empty);
}

// Insere um item no buffer (bloqueia enquanto cheio)
static void buffer_put(bounded_buffer_t* b, int value, int prod_id) {
    pthread_mutex_lock(&b->mtx);

    // Enquanto cheio, esperar a condição "not_full"
    while (b->count == BUFFER_SIZE) {
        // printf("[P%d] buffer cheio, aguardando...\n", prod_id);
        pthread_cond_wait(&b->not_full, &b->mtx);
    }

    // Inserção em buffer circular
    b->data[b->tail] = value;
    b->tail = (b->tail + 1) % BUFFER_SIZE;
    b->count++;

    // Sinaliza que agora há pelo menos um item
    pthread_cond_signal(&b->not_empty);
    pthread_mutex_unlock(&b->mtx);
}

// Remove um item do buffer (bloqueia enquanto vazio)
// Retorna 0 se consumiu item “normal”
// Retorna 1 se consumiu "sentinela" (fim de produção)
static int buffer_get(bounded_buffer_t* b, int* out_value, int cons_id) {
    pthread_mutex_lock(&b->mtx);

    // Enquanto vazio, esperar a condição "not_empty"
    while (b->count == 0) {
        // printf("[C%d] buffer vazio, aguardando...\n", cons_id);
        pthread_cond_wait(&b->not_empty, &b->mtx);
    }

    *out_value = b->data[b->head];
    b->head = (b->head + 1) % BUFFER_SIZE;
    b->count--;

    // Sinaliza que agora há espaço livre
    pthread_cond_signal(&b->not_full);
    pthread_mutex_unlock(&b->mtx);

    // Por convenção, usaremos -1 como “sentinela” de encerramento
    return (*out_value == -1);
}

// ---------------------- Threads ----------------------
static void* producer_thread(void* arg) {
    thread_arg_t* a = (thread_arg_t*)arg;
    bounded_buffer_t* buf = a->buf;
    int id = a->id;

    for (int i = 1; i <= ITEMS_PER_PRODUCER; i++) {
        int item = id * 1000 + i; // só pra identificar quem produziu
        buffer_put(buf, item, id);
        printf("[P%02d] produziu %d\n", id, item);

        // Simula tempo de produção
        usleep(rnd_between(MIN_USLEEP_PROD, MAX_USLEEP_PROD));
    }

    // Ao final, cada produtor não envia sentinela.
    // Quem enviará as sentinelas será a *main*, após todos os produtores acabarem.
    return NULL;
}

static void* consumer_thread(void* arg) {
    thread_arg_t* a = (thread_arg_t*)arg;
    bounded_buffer_t* buf = a->buf;
    int id = a->id;

    for (;;) {
        int item;
        int is_sentinel = buffer_get(buf, &item, id);
        if (is_sentinel) {
            // Recebeu sinal de fim: recoloca a sentinela para outros consumidores
            // não ficarem bloqueados e encerrar todos corretamente.
            buffer_put(buf, -1, -1);
            printf("    [C%02d] recebeu sentinela, encerrando\n", id);
            break;
        }

        // “Processa” item
        printf("    [C%02d] consumiu %d\n", id, item);
        usleep(rnd_between(MIN_USLEEP_CONS, MAX_USLEEP_CONS));
    }
    return NULL;
}

// ---------------------- Programa principal ----------------------
int main(void) {
    srand((unsigned)time(NULL));

    bounded_buffer_t buf;
    buffer_init(&buf);

    pthread_t producers[NUM_PRODUCERS];
    pthread_t consumers[NUM_CONSUMERS];
    thread_arg_t pargs[NUM_PRODUCERS];
    thread_arg_t cargs[NUM_CONSUMERS];

    // Cria consumidores primeiro (não é obrigatório, mas ajuda a já estarem prontos)
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        cargs[i].id = i + 1;
        cargs[i].buf = &buf;
        if (pthread_create(&consumers[i], NULL, consumer_thread, &cargs[i]) != 0) {
            perror("pthread_create consumer");
            exit(EXIT_FAILURE);
        }
    }

    // Cria produtores
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pargs[i].id = i + 1;
        pargs[i].buf = &buf;
        if (pthread_create(&producers[i], NULL, producer_thread, &pargs[i]) != 0) {
            perror("pthread_create producer");
            exit(EXIT_FAILURE);
        }
    }

    // Espera todos os produtores terminarem
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producers[i], NULL);
    }

    // Envia N sentinelas (uma por consumidor) para encerrar o sistema com elegância
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        buffer_put(&buf, -1, -1);
    }

    // Espera consumidores terminarem
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumers[i], NULL);
    }

    buffer_destroy(&buf);
    puts("\n[Fim] Todos os produtores e consumidores encerraram.");
    return 0;
}
