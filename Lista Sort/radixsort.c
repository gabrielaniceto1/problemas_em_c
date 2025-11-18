#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparacoes = 0; // Radix não faz comparações entre elementos
long long trocas = 0;      // aqui vamos contar MOVIMENTOS de elementos

// ---------- FUNÇÕES DO RADIX SORT ----------

// Função auxiliar para pegar o maior elemento do vetor
int getMax(int v[], int n) {
    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

// Counting sort estável por dígito (base 10)
void countingSortPorDigito(int v[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Conta ocorrências de cada dígito
    for (int i = 0; i < n; i++) {
        int digito = (v[i] / exp) % 10;
        count[digito]++;
        trocas++; // contamos o "acesso/movimento lógico" do elemento
    }

    // Transforma count em prefixo (posições finais)
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Monta o vetor de saída de forma estável (percorrendo de trás pra frente)
    for (int i = n - 1; i >= 0; i--) {
        int digito = (v[i] / exp) % 10;
        output[count[digito] - 1] = v[i];
        count[digito]--;
        trocas++; // movimento para o vetor de saída
    }

    // Copia de volta para v[]
    for (int i = 0; i < n; i++) {
        v[i] = output[i];
        trocas++; // movimento de volta
    }
}

void radixsort(int v[], int n) {
    comparacoes = 0; // fica 0, pois não há comparações entre elementos
    trocas = 0;

    int max = getMax(v, n);

    // Aplica counting sort para cada dígito (1, 10, 100, ...)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortPorDigito(v, n, exp);
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
        v[i] = rand(); // pode limitar com %100000 se quiser
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
    radixsort(v, n);
    clock_t fim = clock();

    double tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

    printf("Tamanho: %6d | Cenario: %-20s | Tempo: %8.2f ms | Comparacoes: %12lld | Trocas (mov.): %12lld\n",
           n, nome_cenario, tempo_ms, comparacoes, trocas);

    free(v);
}

// ---------- MAIN ----------

int main(void) {
    srand((unsigned int)time(NULL));

    int tamanhos[] = {1000, 5000, 10000};
    int qtd_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    printf("=== Testes com Radix Sort ===\n\n");
    printf("Formato: Tamanho | Cenario | Tempo | Comparacoes | Trocas (movimentos)\n\n");

    for (int i = 0; i < qtd_tamanhos; i++) {
        int n = tamanhos[i];

        testar_cenario("Ja ordenado", preencher_ordenado, n);
        testar_cenario("Ordenado ao contrario", preencher_invertido, n);
        testar_cenario("Aleatorio", preencher_aleatorio, n);

        printf("--------------------------------------------------------------------------\n");
    }

    return 0;
}
