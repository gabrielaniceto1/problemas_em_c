/*
beecrowd | 1251
Diga-me a Frequência
Por Shahriar Manzoor,  Bangladesh


Dada uma linha de texto, você deve encontrar as frequências de cada um dos caracteres presentes nela. 
As linhas fornecidas não conterão nenhum dos primeiros 32 ou dos últimos 128 caracteres da tabela ASCII. 
É claro que não estamos levando em conta o caracter de fim de linha.

Entrada
A entrada contém vários casos de teste. Cada caso de teste é composto por uma única linha de texto com até 1000 caracteres.

Saída
Imprima o valor ASCII de todos os caracteres presentes e a sua frequência de acordo com o formato abaixo. 
Uma linha em branco deverá separar 2 conjuntos de saída. Imprima os caracteres ASCII em ordem ascendente de frequência. 
Se dois caracteres estiverem presentes com a mesma quantidade de frequência, imprima primeiro o caracter que tem valor ASCII maior. 
A entrada é terminada por final de arquivo (EOF).

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *p, int *q);

int main() {
    char caso[1002];
    int cont = 0;

    while (fgets(caso, 1002, stdin) != NULL) {
        
        caso[strcspn(caso, "\n")] = '\0';

        int arr[128] = {0};
        int caracter[128];
        int quantidade[128];
        int total = 0;

        size_t tamanho = strlen(caso);

        for (int i = 0; i < tamanho; i++) {
            arr[caso[i]]++;
        }

        for (int i = 0; i < 128; i++) {
            if (arr[i] > 0) {
                caracter[total] = i;
                quantidade[total] = arr[i];
                total++;
            }
        }
        for (int i = 0; i < total; i++) {
            for (int j = i + 1; j < total; j++) {
                if (quantidade[i] > quantidade[j] ||
                   (quantidade[i] == quantidade[j] && caracter[i] < caracter[j])) {
                    swap(&quantidade[i], &quantidade[j]);
                    swap(&caracter[i], &caracter[j]);
                }
            }
        }
        if (cont > 0)
        {
            printf("\n");
        }

        cont++;

        for (int i = 0; i < total; i++) {
            printf("%d %d\n", caracter[i], quantidade[i]);
        }

    }

    return 0;
}

void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}
