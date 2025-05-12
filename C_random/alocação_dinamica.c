#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int len;
    int *arr;

    printf("Coloque o tamanho do array\n");
    scanf("%d", &len);

    arr = (int *)malloc(len * sizeof(int));

    printf("Coloque os elementos do array\n");
    for (int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < len; i++){
        printf("%d\n", arr[i]);
    }
    
    free(arr);

    return 0;
}