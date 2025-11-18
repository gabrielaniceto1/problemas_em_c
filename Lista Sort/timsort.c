#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparacoes = 0;
long long trocas = 0;

#define RUN 32
#define MIN(a,b) ((a) < (b) ? (a) : (b))

// ---------- INSERTION SORT USADO PELO TIMSORT (em subarrays) ----------
void insertionSortTim(int v[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int chave = v[i];
        int j = i - 1;

        // similar ao insertion clássico, contando comparações e movimentos
        while (j >= left && v[j] > chave) {
            comparacoes++;          // v[j] > chave
            v[j + 1] = v[j];        // movimento
            trocas++;
            j--;
        }
        if (j >= left) {
            // comparação que fez o while parar (v[j] > chave == falso)
            comparacoes++;
        }

        v[j + 1] = chave;
        trocas++;
    }
}

// ---------- MERGE ESTÁVEL USADO PELO TIMSORT ----------
void mergeTim(int v[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    if (!L || !R) {
        printf("Erro de memoria no merge\n");
        free(L);
        free(R);
        return;
    }

    for (int i = 0; i < n1; i++) {
        L[i] = v[left + i];
        trocas++; // movimento para vetor auxiliar
    }

    for (int j = 0; j < n2; j++) {
        R[j] = v[mid + 1 + j];
        trocas++; // movimento para vetor auxiliar
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparacoes++; // L[i] <= R[j] ?

        if (L[i] <= R[j]) {
            v[k++] = L[i++];
            trocas++; // movimento de volta
        } else {
            v[k++] = R[j++];
            trocas++; // movimento de volta
        }
    }

    while (i < n1) {
        v[k++] = L[i++];
        trocas++;
    }

    while (j < n2) {
        v[k++] = R[j++];
        trocas++;
    }

    free(L);
    free(R);
}

// ---------- TIMSORT ----------
void timsort(int v[], int n) {
    comparacoes = 0;
    trocas = 0;

    // 1) Ordena pequenos blocos (runs) com insertion sort
    for (int i = 0; i < n; i += RUN) {
        int right = MIN(i + RUN - 1, n - 1);
        insertionSortTim(v, i, right);
    }

    // 2) Faz merge de runs em tamanhos crescentes
    for (int size = RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = MIN(left + size - 1, n - 1);
            int right = MIN(left + 2 * size - 1, n - 1);

            if (mid < right) {
                mergeTim(v, left, mid, right);
            }
        }
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
    timsort(v, n);
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

    printf("=== Testes com TimSort (versao simplificada) ===\n\n");
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
