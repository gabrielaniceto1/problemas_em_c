#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparacoes = 0;
long long trocas = 0;

// Insertion Sort exatamente no estilo que você mandou (swap entre vizinhos)
void insertion_sort(int *v, int n) {
    comparacoes = 0;
    trocas = 0;

    for (int i = 1; i < n; i++) {
        int j = i;
        // mesma lógica: enquanto o elemento atual for menor que o anterior, vai trocando
        while (j > 0 && v[j] < v[j - 1]) {
            comparacoes++;                 // comparação v[j] < v[j-1]
            int aux = v[j - 1];           // troca entre vizinhos
            v[j - 1] = v[j];
            v[j] = aux;
            trocas++;
            --j;
        }
        // observação: aqui só contamos comparações quando a condição é verdadeira
        // (igual ao seu código, que também não vê a comparação que para o while)
    }
}

// Gera array já ordenado (crescente)
void preencher_ordenado(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = i;
    }
}

// Gera array ordenado ao contrário (decrescente)
void preencher_invertido(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = n - i;
    }
}

// Gera array com valores aleatórios
void preencher_aleatorio(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand(); // pode usar rand() % 100000 se quiser limitar
    }
}

void testar_cenario(const char *nome_cenario, void (*preencher)(int *, int), int n) {
    int *v = (int *)malloc(n * sizeof(int));
    if (!v) {
        printf("Erro ao alocar memoria para n = %d\n", n);
        return;
    }

    preencher(v, n);

    clock_t inicio = clock();
    insertion_sort(v, n);
    clock_t fim = clock();

    double tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

    printf("Tamanho: %6d | Cenario: %-20s | Tempo: %8.2f ms | Comp.: %12lld | Trocas: %12lld\n",
           n, nome_cenario, tempo_ms, comparacoes, trocas);

    free(v);
}

int main(void) {
    // Para o cenário aleatório ser diferente a cada execução
    srand((unsigned int)time(NULL));

    int tamanhos[] = {1000, 5000, 10000};
    int qtd_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    printf("=== Testes com Insertion Sort ===\n\n");
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
