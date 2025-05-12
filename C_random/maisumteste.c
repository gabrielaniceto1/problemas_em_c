#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *p, int *q);

int main() {
    char caso[1002];

    while (fgets(caso, sizeof(caso), stdin)) {
        // Remove o \n, se houver
        caso[strcspn(caso, "\n")] = '\0';

        int arr[128] = {0};         // Frequência de cada caractere ASCII
        int caracter[128];          // Códigos dos caracteres
        int quantidade[128];        // Quantidades
        int total = 0;              // Total de caracteres únicos

        size_t tamanho = strlen(caso);

        // Conta os caracteres
        for (int i = 0; i < tamanho; i++) {
            arr[caso[i]]++;
        }

        // Armazena os caracteres que aparecem pelo menos uma vez
        for (int i = 0; i < 128; i++) {
            if (arr[i] > 0) {
                caracter[total] = i;
                quantidade[total] = arr[i];
                total++;
            }
        }

        // Ordena por:
        // - frequência crescente
        // - se empatar, por código ASCII decrescente
        for (int i = 0; i < total; i++) {
            for (int j = i + 1; j < total; j++) {
                if (quantidade[i] > quantidade[j] ||
                   (quantidade[i] == quantidade[j] && caracter[i] < caracter[j])) {
                    swap(&quantidade[i], &quantidade[j]);
                    swap(&caracter[i], &caracter[j]);
                }
            }
        }

        // Imprime resultado
        for (int i = 0; i < total; i++) {
            printf("%d %d\n", caracter[i], quantidade[i]);
        }

        printf("\n"); // nova linha após cada caso
    }

    return 0;
}

void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}
