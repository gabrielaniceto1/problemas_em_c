#include <stdio.h>
#include <stdlib.h>

int findMagicIndex(int *array, int tamanho){
    int inicio = 0;
    int fim = tamanho - 1;

    while(inicio <= fim){
        int meio = (inicio + fim) / 2;

        if(array[meio] == meio){
            return meio;
        }

        else if(array[meio] > meio){
            fim = meio - 1;
        }
        else{
            inicio = meio + 1;
        }
    }
    return -1;
}

int main(){

    int array1[] = {-2, -1, 1, 3, 6, 8};
    int tamanho1 = sizeof(array1) / sizeof(array1[0]);

    int resultado = findMagicIndex(array1, tamanho1);

    if(resultado != -1){
        printf("Magic Index encontrado: %d\n", resultado);
        printf("array[%d] = %d\n", resultado, array1[resultado]);
    }
    else{
        printf("Magic Index nao encontrado.\n");
    }

    return 0;
}