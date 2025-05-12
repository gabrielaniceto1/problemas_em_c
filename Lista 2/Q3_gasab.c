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