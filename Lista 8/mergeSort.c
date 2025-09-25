#include <stdio.h>
#include <stdlib.h>

int fatorial(int num){
    if(num == 1 || num == 0){
        return 1;
    }
    return num * fatorial(num - 1);
}
/**
 * Junta (merge) duas partes já ordenadas do vetor:
 * - parte 1: de inicio até meio
 * - parte 2: de meio+1 até fim
 */
void intercalar(int vetor[], int inicio, int meio, int fim) {
    int tamanho = fim - inicio + 1;
    int *aux = malloc(tamanho * sizeof(int)); // espaço temporário para o resultado
    if (!aux) return;

    int iEsq = inicio;     // índice caminhando na metade esquerda
    int iDir = meio + 1;   // índice caminhando na metade direita
    int iAux = 0;          // índice no vetor auxiliar

    // enquanto houver elementos nas duas metades, escolhe o menor e coloca no aux
    while (iEsq <= meio && iDir <= fim) {
        if (vetor[iEsq] <= vetor[iDir]) aux[iAux++] = vetor[iEsq++];
        else                            aux[iAux++] = vetor[iDir++];
    }

    // copia o que sobrou da metade esquerda (se sobrou)
    while (iEsq <= meio) aux[iAux++] = vetor[iEsq++];

    // copia o que sobrou da metade direita (se sobrou)
    while (iDir <= fim) aux[iAux++] = vetor[iDir++];

    // devolve o resultado ordenado para o vetor original
    for (int k = 0; k < tamanho; k++) {
        vetor[inicio + k] = aux[k];
    }

    free(aux);
}

/**
 * Ordena o vetor entre as posições [inicio, fim] usando Merge Sort.
 */
void merge_sort(int vetor[], int inicio, int fim) {
    if (inicio >= fim) return;        // caso-base: 0 ou 1 elemento já está ordenado
    int meio = (inicio + fim) / 2;    // ponto de corte

    merge_sort(vetor, inicio, meio);      // ordena metade esquerda
    merge_sort(vetor, meio + 1, fim);     // ordena metade direita
    intercalar(vetor, inicio, meio, fim); // intercala as duas metades ordenadas
}

int main(void) {
    int v[] = {5, 2, 4, 7, 1, 3};
    int n = sizeof(v)/sizeof(v[0]);

    merge_sort(v, 0, n - 1);

    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    puts("");
    return 0;
}