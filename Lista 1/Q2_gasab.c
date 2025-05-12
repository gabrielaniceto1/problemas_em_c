#include <stdio.h>

float soma();

float media();


int main(){
    char op;
    scanf("%c", &op);

    if (op == 'S'){
        printf("%.1f\n", soma());
    }
    else if(op == 'M'){
        printf("%.1f\n", media());
    }
    else{
        printf("Ocorreu um erro inesperado!\n");
    }
    return 0;
}





float soma(void){
    float matriz[12][12], soma = 0;

    for(int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++)
        {
            scanf("%f", &matriz[i][j]);
            if (j > i)
            {
                soma += matriz[i][j];
            }
            
        }
        
    }
    return soma;
}

float media(void){
    float matriz[12][12], soma = 0, media;

    for(int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++)
        {
            scanf("%f", &matriz[i][j]);
            if (j > i)
            {
                soma += matriz[i][j];
            }
        }
        
    }
    media = soma/66;

    return media;
}