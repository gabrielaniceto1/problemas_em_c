/*
beecrowd | 2722
Pegadinha de Evergreen
Por Neilor Tonin, URI BR Brazil

Evergreen Bushy, um dos duendes ajudantes de Noel, responsável por inventar muitos dos brinquedos distribuídos por Noel e 
também muito conhecido por fazer pegadinhas com o bom velhinho, aprontou mais uma neste ano. 

Como sempre faz todos os anos, Bushy separou os presentes para cada criança colocando um bilhete com o nome dela. 
O problema que ele não se limitou a simplesmente colocar o nome correto da criança no presente: 
ele zoou :) cada um dos nomes misturando as letras segundo uma sequência: duas letras do nome, seguidas 
por duas letras do sobrenome, seguidas por duas letras do nome e por duas letras do sobrenome e assim por diante.

Bem, como Noel está bem cansado e sem tempo para brincadeiras, pediu a você que é expert em programação para fazer um programa que 
converta o nome misturado por Evergreen no nome correto de cada criança.

Apenas um fato curioso: a primeira linha do nome misturado sempre terá um número par de caracteres e a segunda linha, sempre terá o mesmo número de 
caracteres da primeira linha ou um caractere a menos do que a primeira linha.

Entrada
A entrada contém um inteiro N (N < 2000) que indica a quantidade de casos de teste. Cada caso de teste é composto por duas linhas, com no máximo 
100 caracteres cada. Estas duas linhas contém o nome que foi misturado por Evergreen Bushy, que é composto basicamente por 
letras maiúsculas, minúsculas e espaços em branco.

Saída
Com base nas duas linhas de entrada, você deve imprimir o nome correto da criança, seguindo a regra para decifrá-lo conforme descrição acima.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void corrigir_nome(char *frase1, char *frase2, char arr[][202], int cont);

void mostrar_nomes(char arr[][202], int casos);

int main (){
    int casos=0;

    scanf("%d", &casos);
    getchar();

    char arr[casos][202];

    for (int i = 0; i < casos; i++)
    {
        char frase1[101]="", frase2[101]="";

        fgets(frase1, 101, stdin);
        fgets(frase2,101,stdin);

        frase1[strcspn(frase1, "\n")] = '\0';
        frase2[strcspn(frase2, "\n")] = '\0';

        corrigir_nome(frase1, frase2, arr, i);

    }
    mostrar_nomes(arr, casos);
    
    return 0;
}

void corrigir_nome(char *frase1, char *frase2, char arr[][202], int cont){
    char nome[202]="";
    int i=0, j=0, k=0;

    while (frase1[i] != '\0' || frase2[j] != '\0') {
        if (frase1[i] != '\0') {
            nome[k++] = frase1[i++];
        }
        if (frase1[i] != '\0') {
            nome[k++] = frase1[i++];
        }
        if (frase2[j] != '\0') {
            nome[k++] = frase2[j++];
        }
        if (frase2[j] != '\0') {
            nome[k++] = frase2[j++];
        }
    }

    strcpy(arr[cont],nome);
}

void mostrar_nomes(char arr[][202], int casos){

    for(int i = 0; i < casos ; i++){

        printf("%s\n", arr[i]);
        }
}