#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int len, *arr, soma=0, rel;
    printf("Diga o tamanho do array:\n");
    scanf("%d", &len);

    arr = (int *)malloc(len*sizeof(int));

    printf("Digite os elementos da array:\n");
    for (int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < len; i++){
        soma+=arr[i];
    }
    printf("%d\n", soma);


    soma=0;

    printf("Mude o tamanho da array:\n");
    scanf("%d", &rel);

    arr = (int *)realloc(arr, rel*sizeof(int));

    printf("Digite os elementos da nova array:\n");
    for (int i = 0; i < rel; i++){
        scanf("%d", &arr[i]);
        soma+=arr[i];
    }

    printf("%d", soma);

    free(arr);

    return 0;
}