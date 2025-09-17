#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    Node *next;
}Node;

void inserir_inicio(Node **head, Node **tail, int val){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo = NULL) return;
    novo->val = val;
    novo->next = NULL;

    if(*head = NULL){
        novo->next = *head;
        *head = novo;
        *tail = *head;
    }
    else{
        novo->next = *head;
        (*tail)->next = novo;
        *head = novo;
    }
}
void inserir_fim(Node **head, Node **tail, int val){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo = NULL) return;
    novo->val = val;
    novo->next = NULL;

    if(*head = NULL){
        novo->next = *head;
        *head = novo;
        *tail = *head;
    }
    else{
        novo->next = *head;
        (*tail)->next = novo;
        *tail = novo;
    }
}
void printar(Node *head, Node *tail){
    if(head == NULL) return;
    do{
    printf("%d\n", head->val);
    head = head->next;
    }while(tail->next != head);
    
}
int strLista(Node* head, Node *tail){
    if(head == NULL) return 0;
    int cont = 0;
    do{
    cont++;
    head = head->next;
    }while(tail->next != head);
    return cont;
}
void remover_inicio(Node **head, Node **tail){
    Node *aux = *head;
    *head = (*head)->next;
    free(aux);
    (*tail)->next = *head;
}
void remover_fim(Node **head, Node **tail){
    Node *aux = *head;
    while(aux->next != *tail){
        aux = aux->next;
    }
    *tail = aux;
    (*tail)->next = *head;
    aux = aux->next;
    free(aux);
}