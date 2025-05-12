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
