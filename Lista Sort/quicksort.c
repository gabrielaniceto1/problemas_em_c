#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparacoes = 0;
long long trocas = 0;

// ---------- FUNÇÃO TROCA (agora contando trocas) ----------
void troca(int v[], int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
    trocas++; // conta uma troca sempre que acontecer swap
}

// ---------- PARTICAO (com contagem de comparações) ----------
int particao(int v[], int inicio, int fim){
    int pivot, indice, i;
    pivot = inicio;
    indice = fim;

    for (i = fim; i > inicio; i--) {
        comparacoes++; // comparação v[i] >= v[pivot]

        if (v[i] >= v[pivot]) {
            troca(v, i, indice);
            indice--;
        }
    }

    troca(v, pivot, indice);
    return indice;
}

// ---------- QUICKSORT ----------
void quicksort(int v[], int inicio, int fim){
    if (inicio < fim) {
        int indice = particao(v, inicio, fim);
        quicksort(v, inicio, indice - 1);
        quicksort(v, indice + 1, fim);
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
    quicksort(v, 0, n - 1);
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

    printf("=== Testes com Quick Sort ===\n\n");
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
