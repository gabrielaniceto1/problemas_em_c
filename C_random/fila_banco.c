#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int numero;
    struct Node *next;
};

int main(){
    struct Node *head = NULL;
    struct Node *tail = NULL;

    int fila1, fila2, ordemFila, lista1[10000] = {0}, lista2[10000] = {0};
    scanf("%d %d %d", &fila1, &fila2, &ordemFila);

    for(int i = 0; i < fila1; i++){
        int numero;
        scanf(" %d", &numero);
        lista1[i] = numero;
    }
    for(int i = 0; i < fila2; i++){
        int numero;
        scanf(" %d", &numero);
        lista2[i] = numero;
    }

    int i1 = 0, i2 = 0;

    if(ordemFila == 2){
        while (i1 < fila1 || i2 < fila2) {
            if (head == NULL) {
                struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
                if (novo == NULL) {
                    return 1;
                }
                if (i1 < fila1){ 
                    novo->numero = lista1[i1++]; 
                }
                else{ 
                    novo->numero = lista2[i2++]; 
                }
                novo->next = NULL;
                head = novo;
                tail = head;
                continue;
            }
            if (i1 < fila1) {
                struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
                if (novo == NULL) {
                    return 1;
                }
                novo->numero = lista1[i1++];
                novo->next = NULL;
                tail->next = novo;
                tail = tail->next;
            }
            if (i2 < fila2) {
                struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
                if (novo == NULL) {
                    return 1;
                }
                novo->numero = lista2[i2++];
                novo->next = NULL;
                tail->next = novo;
                tail = tail->next;
            }
        }
    }
    else if(ordemFila == 1){
        while (i1 < fila1 || i2 < fila2) {
            if (head == NULL) {
                struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
                if (novo == NULL) {
                    return 1;
                }
                if (i2 < fila2){
                    novo->numero = lista2[i2++]; 
                }
                else{
                    novo->numero = lista1[i1++]; 
                }
                novo->next = NULL;
                head = novo;
                tail = head;
                continue;
            }
            if (i2 < fila2) {
                struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
                if (novo == NULL) {
                    return 1;
                }
                novo->numero = lista2[i2++];
                novo->next = NULL;
                tail->next = novo;
                tail = tail->next;
            }
            if (i1 < fila1) {
                struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
                if (novo == NULL) {
                    return 1;
                }
                novo->numero = lista1[i1++];
                novo->next = NULL;
                tail->next = novo;
                tail = tail->next;
            }
        }
    }

    while(head != NULL){
        struct Node *aux = head;
        printf(" %d\n", head->numero);
        head = head->next;
        free(aux);
    }
    return 0;
}
