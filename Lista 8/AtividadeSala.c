#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
int val; 
struct Node *next; 
struct Node *prev; 
} Node;

void inserir_ordenado(Node **head, Node **tail, int val){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) return;
    novo->val = val;
    novo->next = NULL;
    novo->prev = NULL;

    if(*head == NULL){
        *head = novo;
        *tail = *head;
        return;
    } 
    if(novo->val < (*head)->val){
        novo->next = *head;
        (*head)->prev = novo;
        *head = novo;
        return;
    }
    if((*tail)->val < novo->val){ //ou pode se <= para substituir a excessão de baixo
        (*tail)->next = novo;
        novo->prev = *tail;
        *tail = novo;
        return;
    }
    Node *aux = *head;
    Node *next = aux->next;

    while(aux->next != NULL){
        if(next->val > val){
            novo->next = next;
            novo->prev = aux;
            aux->next = novo;
            next->prev = novo;
            return;
        }
        aux = aux->next;
        next = next->next;
    }
    aux->next = novo;
    novo->prev = aux;
    *tail = novo;
}
void intercalar_listas(Node **head, Node *head1, Node *head2){
    if(head1 == NULL || head2 == NULL) return;
    Node *aux = *head;
    while(head1 != NULL || head2 != NULL){
        if(head1 != NULL){
            Node *novo1 = malloc(sizeof(Node));
            novo1->val = head1->val;
            novo1->next = NULL;
            novo1->prev = NULL;

            if(*head == NULL){
                *head = novo1;
                aux = *head;
            }
            else{
                aux->next = novo1;
                novo1->prev = aux;
                aux = aux->next;
            }
            head1 = head1->next;
        }
        if(head2 != NULL){
            Node *novo2 = malloc(sizeof(Node));
            novo2->val = head2->val;
            novo2->next = NULL;
            novo2->prev = NULL;

            aux->next = novo2;
            novo2->prev = aux;
            aux = aux->next;

            head2 = head2->next;
        }
    }
    
}
void anterior_proximo(Node *head, int val){
    if(head == NULL) return;
    while(head->val != val){
        head = head->next;
    }
    if(head == NULL) return;
    
    int contProx = 0;
    int contAnt = 0;
    Node *aux = head;

    while(aux != NULL){
        contProx++;
        aux = aux->next;
    }
    while(head != NULL){
        contAnt++;
        head = head->prev;
    }
    printf("Anteriores %d | Proximos: %d\n", contAnt, contProx);
}
int main(){

    return 0;
}