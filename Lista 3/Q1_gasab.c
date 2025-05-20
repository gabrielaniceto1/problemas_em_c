/*
beecrowd | 2958
O Rolê Bad Vibes
Por Samuel Eduardo da Silva, IFSULDEMINAS/UFF BR Brazil

A faculdade é um tempo memorável da vida. Grandes coisas acontecem, mas também muita dor e sofrimento, e nesses momentos bons amigos são necessários.

Sabendo disso, Úrisson, ao entrar na universidade, tratou logo de fazer bons amigos e fundar seu grupo de ajuda, Rolê Bad Vibes, o qual 
os membros se ajudam com problemas de disciplinas do curso e de vida.

Como são um grupo de pessoas muito inteligentes, bolaram um esquema para resolução dos problemas:

Para cada problema, era dado um valor de 1 a 9 (na escala de criticidade), e uma letra, D ou V, indicando problema de disciplina ou de vida, respectivamente. 
Com esses dados, colocam em uma matriz, impressa em uma grande cartolina colada na sede do grupo para fácil visualização de todos.

A matriz é uma boa forma de visualizar, porém, ainda causa confusão na hora de escolher os problemas a serem resolvidos no dia, pois os dados ficam muito 
esparsos. Assim, Úrisson gostaria de gerar um relatório, ordenado desses dados.

O critério adotado é: independente da criticidade, os problemas de vida devem ser resolvidos primeiro, 
pois concluíram ser muito complicado conciliar esses problemas com os problemas de disciplinas. Depois, basta ordenar por criticidade.

Úrisson, pediu pra você, veterano de programação, criar um programa que gera este relatório.

Entrada
A primeira linha da entrada contém dois inteiros N e M, indicando, respectivamente, o número de linhas e colunas. 
Nas próximas linhas, é dada a matriz onde cada célula contém dois caracteres, 
o primeiro indicando o nível de criticidade e o segundo se é um problema de vida ou disciplina.

Saída
Relatório ordenado conforme pedido por Úrisson.

*/

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