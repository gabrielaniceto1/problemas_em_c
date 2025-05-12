#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **a, char **b);

int main(){
    int n, m;
    char **matriz = NULL;
    scanf("%d %d", &n, &m);

    matriz = (char**)malloc((n*m)*sizeof(char*));
    for (int i = 0; i < n * m; i++){
            char numero[10];
            scanf("%s", &numero);
            matriz[i] = (char*) malloc((strlen(numero) + 1)*sizeof(char));
            strcpy(matriz[i], numero);
        }
    char **vida = NULL, **disciplina = NULL;
    int cont1=0, cont2=0;

    vida = (char**)malloc((n * m)*sizeof(char*));
    disciplina = (char**)malloc((n * m)*sizeof(char*));

    for (int i = 0; i < n * m; i++){
            if (matriz[i][1] == 'V'){
                vida[cont1] = matriz[i];
                cont1++;
            }
            else{
                disciplina[cont2] = matriz[i];
                cont2++;
            }

    }
    for (int i = 0; i < cont1; i++){
        for (int j = i + 1; j < cont1; j++){
            if (vida[i][0] < vida[j][0]){
                swap(&vida[i],&vida[j]);
            }
        }
    }
    for (int i = 0; i < cont2; i++){
        for (int j = i + 1; j < cont2; j++){
            if (disciplina[i][0] < disciplina[j][0]){
                swap(&disciplina[i],&disciplina[j]);
            }
        }
    }
    int cont = 0;
    while (cont < cont1){
        printf("%s\n", vida[cont]);
        cont++;
    }
    cont = 0;
    while (cont < cont2){
        printf("%s\n", disciplina[cont]);
        cont++;
    }
    for (int i = 0; i < n*m; i++){
        free(matriz[i]);
    }
    
    free(matriz);
    free(vida);
    free(disciplina);
    

    return 0;
}

void swap(char **a, char **b){
    char temp = **a;
    **a = **b;
    **b = temp;
}