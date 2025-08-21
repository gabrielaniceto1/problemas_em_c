#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int numero;
    struct Node *next;
};

int main(){
    int fila1, fila2, ordemFila;
    scanf("%d %d %d", &fila1, &fila2, &ordemFila);
    struct Node *head = NULL;
    struct Node *tail = NULL;
    struct Node *head1 = NULL;
    struct Node *tail1 = NULL;
    struct Node *head2 = NULL;
    struct Node *tail2 = NULL;

    for(int i = 0; i < fila1; i++){
        int num;
        scanf(" %d", &num);
        struct Node *aux = (struct Node *)malloc(sizeof(struct Node));
        aux->numero = num;
        aux->next = NULL;
        if (head1 == NULL){
            head1 = aux;
            tail1 = head1;
        }
        else{
            tail1->next = aux;
            tail1 = tail1->next;
        }
    }
    for(int i = 0; i < fila2; i++){
        int num;
        scanf(" %d", &num);
        struct Node *aux = (struct Node *)malloc(sizeof(struct Node));
        aux->numero = num;
        aux->next = NULL;
        if (head2 == NULL){
            head2 = aux;
            tail2 = head2;
        }
        else{
            tail2->next = aux;
            tail2 = tail2->next;
        }
    }
    if(ordemFila == 1){
        for(int i = 0; i < fila1 + fila2; i++){
            if(head == NULL){
                head = head1;
                tail = head;
            }
            else if(head2 != NULL){
                tail->next = head2;
                tail = tail->next;
                head2 = head2->next;
            }
            else if(head1 != NULL){
                tail->next = head1;
                tail = tail->next;
                head1 = head1->next;
            }
        }
    }
    else if(ordemFila == 2){
        for(int i = 0; i < fila1 + fila2; i++){
            if(head == NULL){
                head = head2;
                tail = head;
            }
            else if(head2 != NULL){
                tail->next = head1;
                tail = tail->next;
                head1 = head1->next;
            }
            else if(head1 != NULL){
                tail->next = head2;
                tail = tail->next;
                head2 = head2->next;
            }
        }
    }
    for(int i = 0; i < fila1 + fila2; i++){
        struct Node *aux = head;
        printf(" %d\n", head->numero);
        aux = head;
        head = head->next;
        free(aux);
    }
    return 0;
}