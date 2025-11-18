#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10000  // maior tamanho de vetor que vamos testar

long long comparacoes = 0;
long long trocas = 0;


void intercala (int inicio, int meio, int fim, int v[]) {
    int inicio_v01 = inicio;
    int inicio_v02 = meio + 1;
    int poslivre = 0;
    int aux[TAMANHO];

    // intercala v[inicio..meio] e v[meio+1..fim] em aux[]
    while (inicio_v01 <= meio && inicio_v02 <= fim) {
        comparacoes++; // comparação entre elementos dos dois lados

        if (v[inicio_v01] <= v[inicio_v02]) {
            aux[poslivre++] = v[inicio_v01++]; // movimento
            trocas++;
        } else {
            aux[poslivre++] = v[inicio_v02++]; // movimento
            trocas++;
        }
    }

    // se existirem núm. em v[inicio_v01] que não foram intercalados
    while (inicio_v01 <= meio) {
        aux[poslivre++] = v[inicio_v01++];
        trocas++;
    }

    // se existirem núm. em v[inicio_v02] que não foram intercalados
    while (inicio_v02 <= fim) {
        aux[poslivre++] = v[inicio_v02++];
        trocas++;
    }

    // retorna os valores do vetor aux para o vetor v
    for (inicio_v01 = inicio; inicio_v01 <= fim; inicio_v01++) {
        v[inicio_v01] = aux[inicio_v01 - inicio];
        trocas++;
    }
}

void mergesort (int inicio, int fim, int v[]) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergesort(inicio, meio, v);
        mergesort(meio + 1, fim, v);
        intercala(inicio, meio, fim, v);
    }
}

// ---------- GERADORES DE CENÁRIOS ----------

void preencher_ordenado(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = i;
    }
}

void preencher_invertido(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = n - i;
    }
}

void preencher_aleatorio(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand();
    }
}

// ---------- TESTE DE UM CENÁRIO ----------

void testar_cenario(const char *nome_cenario, void (*preencher)(int *, int), int n) {
    int *v = (int *)malloc(n * sizeof(int));
    if (!v) {
        printf("Erro ao alocar memoria para n = %d\n", n);
        return;
    }

    preencher(v, n);

    comparacoes = 0;
    trocas = 0;

    clock_t inicio = clock();
    mergesort(0, n - 1, v);
    clock_t fim = clock();

    double tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

    printf("Tamanho: %6d | Cenario: %-20s | Tempo: %8.2f ms | Comparacoes: %12lld | Trocas: %12lld\n",
           n, nome_cenario, tempo_ms, comparacoes, trocas);

    free(v);
}

// ---------- MAIN ----------

int main(void) {
    srand((unsigned int)time(NULL));

    int tamanhos[] = {1000, 5000, 10000};
    int qtd_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    printf("=== Testes com Merge Sort ===\n\n");
    printf("Formato: Tamanho | Cenario | Tempo | Comparacoes | Trocas\n\n");

    for (int i = 0; i < qtd_tamanhos; i++) {
        int n = tamanhos[i];

        testar_cenario("Ja ordenado", preencher_ordenado, n);
        testar_cenario("Ordenado ao contrario", preencher_invertido, n);
        testar_cenario("Aleatorio", preencher_aleatorio, n);

        printf("--------------------------------------------------------------------------\n");
    }

    return 0;
}
