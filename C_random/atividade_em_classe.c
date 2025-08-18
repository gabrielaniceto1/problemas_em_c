#include <stdio.h>
#include <stdlib.h>


struct Node{
    int num;
    struct Node *next;
};

void inserir_no_fim(struct Node **head, int num){
    struct Node *novo = (struct Node *) malloc(sizeof(struct Node));
    if(novo = NULL){
        printf("Erro ao alocar memoria!\n");
    }

    novo->num = num;
    novo->next = NULL;

    if(*head == NULL){
        *head = novo;
    }
    struct Node *atual = *head;

    while(atual->next != NULL){
        atual = atual->next;
    }
    atual->next = novo;
}

void remover_no_fim(struct Node **head, int num){
    struct Node *atual = *head;

    while(atual->next != NULL){
        atual = atual->next;
    }
    free(atual);
}

int valor_especifico(struct Node **head, int num){
    struct Node *atual = *head;
    while(atual->num != num){
        if (atual == NULL){
            return 0;
        }
        atual = atual->next;
    }
    return 1;
}

void inserir_no_local(struct Node **head, int pos, int val){
    int cont = 0;

    struct Node *atual = *head;
    struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
    if(novo == NULL){
            printf("erro ao alocar memoria!");
        }
    novo->num = val;
    novo->next = atual->next;

    if(pos == 0){
        novo->num = *head;
        *head = novo;
        return;
    }

    while(pos -1 != cont){
        atual = atual->next;
        cont++;
    }
    novo->next = atual->next;
    atual->next = novo;
    
}

void remover_no_local(struct Node **head, int pos){
    int cont = 0;
    struct Node *atual = *head;
    if(pos == 0){
        *head = (*head)->next;
        free(atual);
        return;
    }
    while(pos - 1 != cont){
        atual = atual->next;
        cont++;
    }
    struct Node *aux = atual->next;
    atual->next = aux->next;
    free(aux);
}