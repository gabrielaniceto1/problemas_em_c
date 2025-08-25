#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};
void pilha_insert(struct Node **head, int val){
    struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
    if (novo == NULL){
        return -1;
    }
    novo->val = val;
    novo->next = *head;
    *head = novo;
}
void pilha_remove(struct Node **head){
    if(*head != NULL){
        struct Node *aux = *head;
        *head = (*head)->next;
        free(aux);
    }
}
void pilha_imprimir_base(struct Node *head){
    if(head != NULL){
        while(head->next != NULL){
            head = head->next;
        }
        printf("%d\n", head->val);
    }   
}
void imprimir_topo(struct Node *head){
    printf("%d\n", head->val);
}
void pilha_imprimir_pares(struct Node *head){
    if(head != NULL){
        int cont = 0;
        while(head != NULL){
            if(cont % 2 == 0){
                printf(" %d\n", head->val);
            }
            else if(cont == 0){
                printf(" %d\n", head->val);
            }
            head = head->next;
            cont++;
        }
    }
    else{
        printf("Não há elementos na pilha!");
    }  
}