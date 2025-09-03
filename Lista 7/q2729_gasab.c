#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char nome[24];
    struct Node *next;
};
void append(struct Node **head, char nome[24]){
    struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
    if(novo == NULL){
        return;
    }
    strcpy(novo->nome, nome);
    novo->next = NULL;
    if(*head == NULL){
        *head = novo;
    }
    struct Node *aux = *head;
    while(aux->next != NULL){
        if(strcmp(aux->nome,nome) == 0){
            return;
        }
        aux = aux->next;
    }
    aux->next = novo;
}
void bubblesort(struct Node **head){

}
int main(){
    struct Node *head = NULL;
    int casos;
    scanf("%d", &casos);

    return 0;
}