#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char caracter;
    struct Node *next;
};

void inserir_pilha(struct Node **head, char caracter){
    struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
    if(novo == NULL) exit(1);
    novo->caracter = caracter;
    novo->next = *head;
    *head = novo;
}

void remover_pilha(struct Node **head){
    if(!*head) return;
    struct Node *aux = *head;
    *head = (*head)->next;
    free(aux);
}

int main(){
    struct Node *headDO = NULL;
    int cont = -1;


    while (cont != 0) {
        scanf("%d", &cont);

        char desordenado[27], ordenado[27];
        for (int i = 0; i < cont; i++){
            scanf(" %c", &desordenado[i]);
        } 
        desordenado[cont] = '\0';
        for (int i = 0; i < cont; i++){
            scanf(" %c", &ordenado[i]);
        } 
        ordenado[cont] = '\0';

        char operacoes[64];
        operacoes[0] = '\0';

        int i_empilhar_desordenado = 0;
        int i_empilhar_ordenado = 0;

        while(i_empilhar_ordenado < cont) {
            while((headDO == NULL || headDO->caracter != ordenado[i_empilhar_ordenado]) && i_empilhar_desordenado < cont) {
                inserir_pilha(&headDO, desordenado[i_empilhar_desordenado]);
                i_empilhar_desordenado++;
                strcat(operacoes, "I");
            }

            if(headDO != NULL && headDO->caracter == ordenado[i_empilhar_ordenado]) {
                remover_pilha(&headDO);
                strcat(operacoes, "R");
                i_empilhar_ordenado++;
            }
            else{
                strcat(operacoes, " Impossible");
                break;
            }
        }

        printf("%s\n", operacoes);

        while (headDO != NULL){
            remover_pilha(&headDO);
        } 
    }
    return 0;
}
