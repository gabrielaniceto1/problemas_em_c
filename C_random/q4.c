#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *p, int *q);

int main (){
    char caso[1002]={}; 

    while(fgets(caso,1002,stdin) != NULL){

    caso[strcspn(caso,"\n")] = '\0';

    size_t tamanho = strlen(caso);
    int caracter[1002] = {};
    int quantidade[1000]={};
    int arr[128]={0};
    int total=0;
    int cont =0;

    for (int i = 0; i < tamanho; i++) {
        arr[(int)caso[i]]++;
    }

    for (int i = 0; i < 128; i++) {
        if (arr[i] > 0) {
            caracter[total] = i;
            quantidade[total] = arr[i];
            total++;
        }
    }
    if(cont++>0){
        printf("\n");
    }
    for (int i = 0; i < total; i++)
    {
        for (int j = 0; j < total; j++)
        {
            if(quantidade[i] > quantidade[j] || (quantidade[i] == quantidade[j] && caracter[i] > caracter[j])){
                swap(&caracter[i],&caracter[j]);
                swap(&quantidade[i],&quantidade[j]);
            }
        }
        
    }
    
    for(int i = 0; i < total; i++){
        if(arr[i] > 0){
        printf("%d %d\n", caracter[i], quantidade[i]);
        } 
    }
    }
    
    return 0;
}

void swap(int *p, int *q){
    int temp = 0;

    temp = *p;
    *p = *q;
    *q = temp;
}