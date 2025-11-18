#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparacoes = 0;
long long trocas = 0;

// ---------- TROCA (contando trocas) ----------
void troca(int v[], int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
    trocas++; // conta 1 troca sempre que swap é feito
}

// ---------- HEAPIFY (com contagem de comparações) ----------
void heapify(int v[], int tam, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < tam) {
        comparacoes++;                // comparação v[esq] > v[maior]
        if (v[esq] > v[maior])
            maior = esq;
    }

    if (dir < tam) {
        comparacoes++;                // comparação v[dir] > v[maior]
        if (v[dir] > v[maior])
            maior = dir;
    }

    if (maior != i) {
        troca(v, i, maior);
        heapify(v, tam, maior);
    }
}

// ---------- HEAPSORT ----------
void heapsort(int v[], int tam) {
    // constroi heap (reorganiza o array)
    for (int i = (tam - 1) / 2; i >= 0; i--)
        heapify(v, tam, i);

    // extrai elementos do heap um por um
    for (int i = tam - 1; i > 0; i--) {
        troca(v, 0, i);     // move a raiz (maior) para o fim
        heapify(v, i, 0);   // chama heapify na heap reduzida
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
    heapsort(v, n);
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

    printf("=== Testes com Heap Sort ===\n\n");
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
