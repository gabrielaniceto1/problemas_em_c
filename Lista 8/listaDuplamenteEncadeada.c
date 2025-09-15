#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    Node *next;
    Node *prev;
}Node;

void inserir_inicio(Node **head, int val){
    Node *novo = (Node *)malloc(sizeof(Node));
    if(novo == NULL) return;
    novo->val = val;
    novo->next = *head;
    novo->prev = NULL;
    if(*head != NULL){
        (*head)->prev = novo;
    }
    *head = novo;
}
void inserir_final(Node **head, int val){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) return;
    novo->val = val;
    novo->next = NULL;
    novo->prev = NULL;
    if(*head == NULL){
        *head = novo;
        return;
    }
    Node *aux = *head;
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = novo;
    novo->prev = aux;
}
void inserir_final_tail(Node **head, Node **tail, int val){
    Node *novo =(Node*)malloc(sizeof(Node));
    if(novo == NULL) return;
    novo->val = val;
    novo->next = NULL;
    novo->prev == NULL;

    if(*head == NULL){
        *head = novo;
        *tail = *head;
        return;
    }
    (*tail)->next = novo;
    novo->prev = *tail;
    *tail = novo;
}
void imprimir_fim_inicio(Node *head){
    while(head->next != NULL){
        head = head->next;
    }
    while(head != NULL){
        printf("%d ", head->val);
        head = head->prev;
    }
}
void remover_inicio(Node **head){
    if(*head == NULL) return;
    if((*head)->next == NULL){
        free(*head);
        return;
    }
    Node *aux = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(aux);
}
void remover_final(Node **head){
    if(head == NULL) return;
    if((*head)->next == NULL){
        free(*head);
        return;
    }
    Node *aux = *head;
    while(aux->next->next != NULL){
        aux = aux->next;
    }
    Node *dell = aux->next;
    free(dell);
    aux->next = NULL;
}
void remocao_final_tail(Node **head, Node **tail){
    if(*head == NULL) return;
    if(*head == *tail){
        free(*head);
        *tail = NULL;
        return;
    }
    Node *aux = *tail;
    *tail = (*tail)->prev;
    free(aux);
    (*tail)->next = NULL;
}
int main(){

    return 0;
}