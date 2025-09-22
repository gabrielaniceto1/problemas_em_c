#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int val;
    Node *next;
    Node *prev;
}Node;

void inserir_inicio(Node **head, Node **tail, int val){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) return;
    novo->val = val;
    if(*head == NULL){
        novo->next = novo;
        novo->prev = novo;

        *head = novo;
        *tail = *head;
    }
    else{
        novo->next = *head;
        novo->prev = *tail;

        (*tail)->next = novo;
        (*head)->prev = novo;

        *head = (*head)->prev;
    }
}
void inserir_fim(Node **head, Node **tail, int val){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) return;
    novo->val = val;

    if(*head == NULL){
        novo->next = novo;
        novo->prev = novo;
        
        *head = novo;
        *tail = *head;
    }
    else{
        novo->next = *head;
        novo->prev = *tail;

        (*tail)->next = novo;
        (*head)->prev = novo;

        *tail = (*tail)->next;
    }
}
void remover_inicio(Node **head, Node **tail){   
    if(*head == NULL) return;

    if(*head == *tail){
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else{
        Node *aux = *head;
        *head = (*head)->next;

        (*tail)->next = *head;
        (*head)->prev = *tail;

        free(aux);
    }       
}
void remover_fim(Node **head, Node **tail){
    if(*head == NULL) return;

    if(*head == *tail){
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else{
        Node *aux = *tail;
        *tail = (*tail)->prev;
        (*head)->prev = *tail;
        (*tail)->next = *head;

        free(aux);
    }
}
void printar(Node *head, Node *tail){
    if(head == NULL) return;
    if(head == tail){
        printf("%d\n", head->val);
        return;
    }
    do{
        printf("%d ", head->val);
        head = head->next;
    }while(tail->next != head);
    printf("\n");
}
void printar_inverso(Node *head, Node *tail){
    if(head == NULL) return;
    if(head == tail){
        printf("%d\n", head->val);
        return;
    }
    do{
        printf("%d ", tail->val);
        tail = tail->prev;
    }while(head->prev != tail);
    printf("\n");
}
void inserir_na_posicao(Node **head, Node **tail, int val, int posicao){
    if(posicao < 1) posicao = 1;

    Node *novo = (Node *)malloc(sizeof(Node));
    if(novo == NULL) return;
    novo->val = val;

    if(*head == NULL){
        novo->next = novo;
        novo->prev = novo;

        *head = novo;
        *tail = novo;
        printf("Valor adicionado no inicio pela head ser igual a NULL\n");
        return;
    }
    if(posicao == 1){
        novo->next = *head;
        novo->prev = *tail;

        (*head)->prev = novo;
        (*tail)->next = novo;
        *head = novo;
        return;
    }
    int len = 1;
    Node *aux = *head;
    do{
        len++;
        aux = aux->next;
    }while(aux != (*tail)->next);

    if(posicao >= len){
        novo->next = *head;
        novo->prev = *tail;

        (*tail)->next = novo;
        (*head)->prev = novo;
        *tail = (*tail)->next;

        printf("Inserido no fim, devido a posição ser maior ou igual que o tamanho da lista");
    }
    else{
        Node *aux = *head;
        Node *prev = aux->prev;
        int cont = 1;

        while(cont != posicao){
            cont++;
            aux = aux->next;
            prev = prev->next;
        }
        novo->next = aux;
        novo->prev = prev;

        prev->next = novo;
        aux->prev = novo;
    }
}
void remover_na_posicao(Node **head, Node **tail, int posicao){
    if(*head == NULL) printf("Não há o que remover\n");

    if(posicao < 1) posicao = 1;

    int len = 1;
    Node *aux = *head;
    do{
        len++;
        aux = aux->next;
    }while(aux != (*tail)->next);

    if(*head == *tail){
        free(*head);
        *head = NULL;
        *tail = NULL;
        printf("Removido o unico elemento\n");
        return;
    }
    if(posicao == 1){
        Node *aux = *head;
        *head = (*head)->next;
        (*tail)->next = *head;
        (*head)->prev = *tail;
        free(aux);
        return;
    }
    if(posicao >= len){
        Node *aux = *tail;
        *tail = (*tail)->prev;
        (*head)->prev = *tail;
        (*tail)->next = *head;
        free(aux);
        printf("Remoção no fim pois a posição é maior ou igual a o tamanho da lista\n");
    }
    else{
        int cont = 1;
        Node *aux = *head;
        while(cont != posicao){
            cont++;
            aux = aux->next;
        }
        Node *prev = aux->prev;
        Node *next = aux->next;

        prev->next = next;
        next->prev = prev;
        free(aux);
    }
}
//arara
int palindromo(Node *head, Node *tail){
    if(head == NULL) return 0;
    int len = 1;
    Node *aux = head;
    do{
        len++;
        aux = aux->next;
    }while(aux != tail->next);
    if(len < 3){
        printf("Menor que 3 elementos\n");
        return 0;
    } 
    while(head->val == tail->val){
        if(head->prev == tail || head == tail) return 1;
        head = head->next;
        tail = tail->prev;
    }
    return 0;
}
int main(){

    return 0;
}