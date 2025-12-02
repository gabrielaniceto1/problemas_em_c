#include <stdio.h>
#include <stdlib.h>

int busca_linear(int *arr, int tam, int val){
    for(int i = 0; i < tam; i++){
        if(arr[i] == val) return i;
    }
    return -1;
}
int busca_binaria(int *arr, int tam, int val){
    //não se deve usar a ordenação, mas caso o vetor esteja desordenado não funciona por isso coloquei para lembrar
    for(int i = 1; i < tam; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j - 1]){
            int aux = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = aux;
            j--;
        }
    }
    int inicio = 0;
    int fim = tam - 1;
    while(inicio <= fim){
        int meio = inicio + (fim - inicio) / 2;
        if(arr[meio] == val) return meio;
        else if(val > arr[meio]){
            inicio = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }
    return -1;
}