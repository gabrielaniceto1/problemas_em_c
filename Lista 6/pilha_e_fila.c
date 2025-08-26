#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
    char nome[30]; 
    struct  Pessoa *next;
}; 
void inserir_fila(struct Pessoa **head, struct Pessoa **tail, char *nome){
    if(*head == NULL){
        *head = (struct Pessoa *)malloc(sizeof(struct Pessoa));
        if(*head == NULL){
            return;
        }
        strcpy((*head)->nome,nome);
        (*head)->next = NULL;
        *tail = *head;  
    }
    else{
        struct Pessoa *novo = (struct Pessoa *)malloc(sizeof(struct Pessoa));
        if(novo == NULL){
            return;
        }
        strcpy(novo->nome,nome);
        novo->next = NULL;
        (*tail)->next = novo;
        *tail = novo;
    }
}
void inserir_pilha(struct Pessoa **head, char *nome){
    struct Pessoa *novo = (struct Pessoa *)malloc(sizeof(struct Pessoa));
    if (novo == NULL){
        return;
    }
    strcpy(novo->nome,nome);
    novo->next = *head;
    *head = novo;
}
void concatenar_filas(struct Pessoa **head_pilha1, struct Pessoa *head_fila1, struct Pessoa *head_fila2){
    while(head_fila1 != NULL){
        inserir_pilha(head_pilha1, head_fila1->nome);
        head_fila1 = head_fila1->next;
    }
    while(head_fila2 != NULL){
        inserir_pilha(head_pilha1, head_fila2->nome);
        head_fila2 = head_fila2->next;
    }
}
void intercalar_filas(struct Pessoa **head_pilha2, struct Pessoa *head_fila1, struct Pessoa *head_fila2){
    while(head_fila1 != NULL || head_fila2 != NULL){
        if(head_fila1 != NULL){
            inserir_pilha(head_pilha2, head_fila1->nome);
            head_fila1 = head_fila1->next;
        }
        if(head_fila2 != NULL){
            inserir_pilha(head_pilha2, head_fila2->nome);
            head_fila2 = head_fila2->next;
        }
    }
}
void printar(struct Pessoa *head){
    while(head != NULL){
        printf(" %s", head->nome);
        head = head->next;
    }
}
int main(){
    struct Pessoa *head_fila1 = NULL;
    struct Pessoa *tail_fila1 = NULL;
    struct Pessoa *head_fila2 = NULL;
    struct Pessoa *tail_fila2 = NULL;
    struct Pessoa *head_pilha1 = NULL;
    struct Pessoa *head_pilha2 = NULL;
    printf("Digite a seguir 10 nomes parta a fila 1: \n");
    for(int i = 0; i < 10; i++){
        char nome[30];
        scanf(" %29[^\n]", nome);
        inserir_fila(&head_fila1, &tail_fila1, nome);
    }
    printf("Digite a seguir 10 nomes parta a fila 2: \n");
    for(int i = 0; i < 10; i++){
        char nome[30];
        scanf(" %29[^\n]", nome);
        inserir_fila(&head_fila2, &tail_fila2, nome);
    }
    concatenar_filas(&head_pilha1, head_fila1, head_fila2);
    intercalar_filas(&head_pilha2, head_fila1, head_fila2);
    printar(head_fila1);
    printf(" \n");
    printar(head_fila2);
    printf(" \n");
    printar(head_pilha1);
    printf(" \n");
    printar(head_pilha2);
    return 0;
}