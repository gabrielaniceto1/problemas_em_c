#include <stdio.h>

/* troca os valores apontados por a e b */
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
 * PARTIÇÃO (Lomuto espelhado):
 * - Pivô = primeiro elemento (v[inicio]).
 * - Vamos varrer de trás pra frente (j = fim -> inicio+1).
 * - Mantemos um índice i que delimita a "zona dos > pivô" do lado direito.
 *
 * Ideia:
 *   i começa em fim + 1 (ou seja, "fora" do vetor).
 *   Sempre que acharmos v[j] > pivô, diminuímos i e jogamos v[j] para a
 *   faixa da direita (trocando com v[i-1]).
 *   No fim, colocamos o pivô em v[i-1], que é a posição correta dele.
 *
 * Resultado:
 *   [inicio .. p-1]  -> elementos <= pivô
 *   [p]              -> pivô na posição final
 *   [p+1 .. fim]     -> elementos  > pivô
 */
int partition_primeiro_pivo_dec(int v[], int inicio, int fim) {
    int pivo = v[inicio];   // pivô = primeiro elemento
    int i = fim + 1;        // i marca o início (à direita) dos > pivô

    // percorre de trás pra frente, SEM incluir o pivô (começa em fim e vai até inicio+1)
    for (int j = fim; j >= inicio + 1; j--) {
        if (v[j] > pivo) {
            // achamos um elemento > pivô: ele deve ir para a "zona da direita"
            i--;                // recua a fronteira da direita
            swap(&v[i], &v[j]); // leva v[j] para a zona dos maiores
        }
    }

    // agora, todos os > pivô estão em [i .. fim]
    // e todos os <= pivô ficaram em [inicio+1 .. i-1]
    // colocamos o pivô exatamente antes da zona dos maiores
    swap(&v[inicio], &v[i - 1]);

    return i - 1; // posição final do pivô
}

/*
 * QUICK SORT (recursivo) com pivô no primeiro elemento.
 */
void quicksort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = partition_primeiro_pivo_dec(v, inicio, fim);
        quicksort(v, inicio, p - 1); // parte esquerda (<= pivô)
        quicksort(v, p + 1, fim);    // parte direita (> pivô)
    }
}

/* imprime o vetor */
void imprime(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%c", v[i], (i == n - 1) ? '\n' : ' ');
    }
}

int main(void) {
    int v[] = {10, 7, 8, 9, 1, 5, 5, 2};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Antes:  ");
    imprime(v, n);

    quicksort(v, 0, n - 1);

    printf("Depois: ");
    imprime(v, n);

    return 0;
}
