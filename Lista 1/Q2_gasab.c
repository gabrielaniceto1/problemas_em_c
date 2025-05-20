/*
beecrowd | 1183
Acima da Diagonal Principal
Por Neilor Tonin, URI  Brasil

Leia um caractere maiúsculo, que indica uma operação que deve ser realizada e uma matriz M[12][12]. 
Em seguida, calcule e mostre a soma ou a média considerando somente aqueles elementos que estão acima da diagonal principal da matriz.

Entrada
A primeira linha de entrada contem um único caractere Maiúsculo O ('S' ou 'M'), indicando a operação (Soma ou Média) 
que deverá ser realizada com os elementos da matriz. Seguem os 144 valores de ponto flutuante que compõem a matriz.

Saída
Imprima o resultado solicitado (a soma ou média), com 1 casa após o ponto decimal.
*/

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