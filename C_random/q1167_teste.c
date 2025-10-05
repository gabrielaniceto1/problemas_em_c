#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node{
    char nome[40];
    int val;
    struct Node *next;
    struct Node *prev;
}Node;

void inserir_fim(Node **head, Node **tail, int val, char *nome){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) return;
    novo->val = val;
    strcpy(novo->nome,nome);

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
void getNomeVencedor(Node **head, Node **tail, char *nomeVencedor){
    if(*head == NULL){
        strcpy(nomeVencedor, "");
        return;
    }  

    if(*head == *tail){
        strcpy(nomeVencedor, (*head)->nome);
        free(*head);
        *head = NULL;
        *tail = NULL;
        return;
    }

    int len = 0;
    Node *count = *head;
    do{
        len++;
        count = count->next;
    }while(count != (*tail)->next);

    int casasAndar = (*head)->val;
    Node *aux = (casasAndar % 2 == 0) ? (*head)->next : (*head)->prev;
    
    while(*head != *tail){

        int passos = ((casasAndar - 1) % len) + 1;

        if(casasAndar % 2 == 0){
            int cont = 1;
            
            while(cont < passos){
                aux = aux->next;
                cont++;
            }
            casasAndar = aux->val;
            Node *prev = aux->prev;
            Node *next = aux->next;
            Node *remover = aux;

            prev->next = next;
            next->prev = prev;

            if(aux == *head) *head = next;
            if(aux == *tail) *tail = prev;

            free(remover);
            aux = (casasAndar % 2 == 0) ? next : prev;
        }
        else{
            int cont = 1;
            
            while(cont < passos){
                aux = aux->prev;
                cont++;
            }
            casasAndar = aux->val;
            Node *prev = aux->prev;
            Node *next = aux->next;
            Node *remover = aux;

            prev->next = next;
            next->prev = prev;

            if(aux == *head) *head = next;
            if(aux == *tail) *tail = prev;

            free(remover);
            aux = (casasAndar % 2 == 0) ? next : prev;
        }
        len--;
    }
    strcpy(nomeVencedor, (*head)->nome);
    free(*head);
    *head = *tail = NULL;
}
int main(){
    int numeroCriancas;
    while (1){
        if (scanf("%d", &numeroCriancas) != 1) break;
        if(numeroCriancas == 0) break;
        Node *head = NULL;
        Node *tail = NULL;
        char nomeVencedor[40];

        for (int i = 0; i < numeroCriancas; i++){
            char nome[40];
            int numeroFicha;

            scanf("%39s %d", nome, &numeroFicha);

            inserir_fim(&head, &tail, numeroFicha, nome);
        }
        getNomeVencedor(&head, &tail, nomeVencedor);

        printf("Vencedor(a): %s\n", nomeVencedor); 
    }
    
    return 0;
}