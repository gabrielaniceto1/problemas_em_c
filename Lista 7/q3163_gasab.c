#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char nome[6];
    struct Node *next;
};
void inserir_fila(struct Node **head, struct Node **tail, char *nome){
    struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
        strcpy(novo->nome, nome);
        novo->next = NULL;
    if(*head == NULL){
        *head = novo;
        *tail = novo;
    }
    else{
        (*tail)->next = novo;
        *tail = (*tail)->next;
    }
}
int main(){
    struct Node *headN = NULL;
    struct Node *tailN = NULL;
    struct Node *headS = NULL;
    struct Node *tailS = NULL;
    struct Node *headL = NULL;
    struct Node *tailL = NULL;
    struct Node *headO = NULL;
    struct Node *tailO = NULL;

    char input[3];

    while(1){
        char var[6];
        scanf(" %5[^\n]", var);
        if(var[0] == '-'){
            strcpy(input,var);
        }
        else if(var[0] == '0'){
            break;
        }
        else{
            if(strcmp(input,"-1") == 0){
                inserir_fila(&headO, &tailO, var);
            }
            else if(strcmp(input,"-2") == 0){
                inserir_fila(&headS, &tailS, var);
            }
            else if(strcmp(input,"-3") == 0){
                inserir_fila(&headN, &tailN, var);
            }
            else if(strcmp(input,"-4") == 0){
                inserir_fila(&headL, &tailL, var);
            }
        }
        
    }
    int first = 1;

    while(headN != NULL || headS != NULL || headL != NULL || headO != NULL){
        if(headO != NULL){
            if (!first) putchar(' ');
            printf("%s", headO->nome);
            headO = headO->next;
            first = 0;
        }
        if(headN != NULL){
            if (!first) putchar(' ');
            printf("%s", headN->nome);
            headN = headN->next;
            first = 0;
        }
        if(headS != NULL){
            if (!first) putchar(' ');
            printf("%s", headS->nome);
            headS = headS->next;
            first = 0;
        }
        if(headL != NULL){
            if (!first) putchar(' ');
            printf("%s", headL->nome);
            headL = headL->next;
            first = 0;
        }
    }
    printf("\n");
    return 0;
}