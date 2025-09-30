#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int v[], int inicio, int fim, int depth);
void troca(int v[], int i, int j);
int particao(int v[], int inicio, int fim);
int particao_aleatoria(int v[], int inicio, int fim);
void printArray(int arr[], int start, int end, int depth);

int main()
{
    srand(time(NULL));
    int vet[100];
    int TAM = sizeof(vet) / sizeof(int);
    for (int i = 0; i < TAM; i++){
        vet[i] = rand() % 100;
    }
    

    quicksort(vet, 0, TAM - 1, 0);

    return 0;
}

void printArray(int arr[], int start, int end, int depth)
{
    for (int i = 0; i < depth; i++)
    {
        printf("    ");
    }

    printf("[");
    for (int i = start; i <= end; i++)
    {
        printf("%d", arr[i]);
        if (i < end)
            printf(", ");
    }
    printf("]\n");
}

void quicksort(int v[], int inicio, int fim, int depth)
{
    if (inicio < fim)
    {

        for (int i = 0; i < depth; i++)
        {
            printf("    ");
        }
        printf("profundidade: %d\n", depth);
        for (int i = 0; i < depth; i++)
        {
            printf("    ");
        }
        printf("vetor de entrada: \n");
        printArray(v, inicio, fim, depth);
        for (int i = 0; i < depth; i++)
        {
            printf("    ");
        }
        printf("pivot: %d\n", v[inicio]);
        for (int i = 0; i < depth; i++)
        {
            printf("    ");
        }
        printf("trocas: ");
        int indice = particao(v, inicio, fim);
        printf("\n");

        for (int i = 0; i < depth; i++)
        {
            printf("    ");
        }
        printf("vetor apos funcao particao:\n");

        printArray(v, inicio, fim, depth);
        for (int i = 0; i < depth; i++)
        {
            printf("    ");
        }
        printf("====================================\n");

        quicksort(v, inicio, indice - 1, depth + 1);
        quicksort(v, indice + 1, fim, depth + 1);

        for (int i = 0; i < depth; i++)
        {
            printf("    ");
        }
        printf("vetor de saida da profundidade %d:\n", depth);

        printArray(v, inicio, fim, depth);
        for (int i = 0; i < depth; i++)
        {
            printf("    ");
        }
        printf("====================================\n");
    }
}

int particao(int v[], int inicio, int fim)
{
    int pivot, indice;
    pivot = v[inicio];
    indice = fim;

    for (int i = fim; i > inicio; i--)
        if (v[i] >= pivot)
        {
            troca(v, i, indice);
            indice--;
        }

    troca(v, inicio, indice);
    return indice;
}

void troca(int v[], int i, int j)
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
    if (i != j)
        printf("(%d, %d) ", v[i], v[j]);
}

int particao_aleatoria(int v[], int inicio, int fim)
{
    int indice = (rand() % (fim - inicio + 1)) + inicio;
    troca(v, indice, inicio);
    return particao(v, inicio, fim);
}