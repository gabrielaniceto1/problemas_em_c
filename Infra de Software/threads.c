#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define BUFFER_SIZE           10
#define NUM_PRODUTORES        3
#define NUM_CONSUMIDORES      2
#define ITENS_POR_PRODUTOR   20
#define POISON_PILL         (-1)  // marcador especial para encerrar consumidores

// Buffer circular
static int buffer[BUFFER_SIZE];
static int idx_in  = 0;
static int idx_out = 0;

// Sincronização
static HANDLE hMutex   = NULL; // exclusão mútua para acessar o buffer (idx_in/idx_out/dados)
static HANDLE hSlots   = NULL; // semáforo: quantas vagas existem (começa em BUFFER_SIZE)
static HANDLE hItems   = NULL; // semáforo: quantos itens existem (começa em 0)

// Contador global de itens reais consumidos (não conta POISON_PILL)
static volatile LONG totalConsumidos = 0;
static const int TOTAL_A_PRODUZIR = NUM_PRODUTORES * ITENS_POR_PRODUTOR;

static void dorme_ms(DWORD ms) {
    Sleep(ms);
}

// Deposita um item no buffer (pré-condições: já fez down em hSlots e pegou o hMutex)
static void deposita_no_buffer(int item) {
    buffer[idx_in] = item;
    idx_in = (idx_in + 1) % BUFFER_SIZE;
}

// Retira um item do buffer (pré-condições: já fez down em hItems e pegou o hMutex)
static int retira_do_buffer(void) {
    int item = buffer[idx_out];
    idx_out = (idx_out + 1) % BUFFER_SIZE;
    return item;
}

DWORD WINAPI thread_produtor(LPVOID lpParam) {
    int id = (int)(SIZE_T)lpParam;

    for (int i = 0; i < ITENS_POR_PRODUTOR; i++) {
        int item = id * 1000 + i;      // só para identificação
        dorme_ms(10 + (rand() % 40));  // simula tempo de produção

        // Espera vaga
        WaitForSingleObject(hSlots, INFINITE);
        // Entra na região crítica
        WaitForSingleObject(hMutex, INFINITE);

        deposita_no_buffer(item);
        printf("[Produtor %d] depositou %d | in=%d out=%d\n", id, item, idx_in, idx_out);

        // Sai da região crítica
        ReleaseMutex(hMutex);
        // Sinaliza que há um novo item
        ReleaseSemaphore(hItems, 1, NULL);
    }
    return 0;
}

DWORD WINAPI thread_consumidor(LPVOID lpParam) {
    int id = (int)(SIZE_T)lpParam;

    for (;;) {
        // Espera item
        WaitForSingleObject(hItems, INFINITE);
        // Entra na região crítica
        WaitForSingleObject(hMutex, INFINITE);

        int item = retira_do_buffer();
        printf("                  [Consumidor %d] retirou %d | in=%d out=%d\n",
               id, item, idx_in, idx_out);

        // Sai da região crítica
        ReleaseMutex(hMutex);
        // Libera uma vaga
        ReleaseSemaphore(hSlots, 1, NULL);

        // Se for pílula de veneno, encerra
        if (item == POISON_PILL) {
            break;
        }

        // “Consome” o item
        dorme_ms(15 + (rand() % 60));
        InterlockedIncrement(&totalConsumidos);
    }
    return 0;
}

int main(void) {
    srand((unsigned)GetTickCount());

    // Cria sincronizadores
    hMutex = CreateMutex(NULL, FALSE, NULL);
    if (!hMutex) { fprintf(stderr, "Falha CreateMutex\n"); return 1; }

    hSlots = CreateSemaphore(NULL, BUFFER_SIZE, BUFFER_SIZE, NULL);
    if (!hSlots) { fprintf(stderr, "Falha CreateSemaphore(hSlots)\n"); return 1; }

    hItems = CreateSemaphore(NULL, 0, BUFFER_SIZE, NULL);
    if (!hItems) { fprintf(stderr, "Falha CreateSemaphore(hItems)\n"); return 1; }

    // Cria produtores
    HANDLE produtores[NUM_PRODUTORES];
    for (int i = 0; i < NUM_PRODUTORES; i++) {
        produtores[i] = CreateThread(
            NULL, 0, thread_produtor, (LPVOID)(SIZE_T)(i + 1), 0, NULL
        );
        if (!produtores[i]) {
            fprintf(stderr, "Falha ao criar produtor %d\n", i + 1);
            return 1;
        }
    }

    // Cria consumidores
    HANDLE consumidores[NUM_CONSUMIDORES];
    for (int i = 0; i < NUM_CONSUMIDORES; i++) {
        consumidores[i] = CreateThread(
            NULL, 0, thread_consumidor, (LPVOID)(SIZE_T)(i + 1), 0, NULL
        );
        if (!consumidores[i]) {
            fprintf(stderr, "Falha ao criar consumidor %d\n", i + 1);
            return 1;
        }
    }

    // Aguarda produtores terminarem
    WaitForMultipleObjects(NUM_PRODUTORES, produtores, TRUE, INFINITE);

    // Injeta "poison pills" para acordar e encerrar consumidores (1 por consumidor)
    for (int i = 0; i < NUM_CONSUMIDORES; i++) {
        // precisa respeitar a disciplina: esperar vaga, entrar no buffer, etc.
        WaitForSingleObject(hSlots, INFINITE);
        WaitForSingleObject(hMutex, INFINITE);

        deposita_no_buffer(POISON_PILL);

        ReleaseMutex(hMutex);
        ReleaseSemaphore(hItems, 1, NULL);
    }

    // Aguarda consumidores terminarem
    WaitForMultipleObjects(NUM_CONSUMIDORES, consumidores, TRUE, INFINITE);

    printf("\nProduzidos = %d | Consumidos (reais) = %ld\n",
           TOTAL_A_PRODUZIR, totalConsumidos);

    // Limpeza
    for (int i = 0; i < NUM_PRODUTORES; i++) CloseHandle(produtores[i]);
    for (int i = 0; i < NUM_CONSUMIDORES; i++) CloseHandle(consumidores[i]);
    CloseHandle(hMutex);
    CloseHandle(hSlots);
    CloseHandle(hItems);

    return 0;
}