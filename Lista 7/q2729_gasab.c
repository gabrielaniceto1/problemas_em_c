#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char nome[24];
    struct Node *next;
};
void inserir(struct Node **head, char nome[24]){
    struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
    if(novo == NULL){
        return;
    }
    strcpy(novo->nome,nome);
    novo->next = NULL;
    if(*head == NULL){
        *head = novo;
        return;
    }
    struct Node *aux = *head;
    while(aux != NULL){
        if(strcmp(aux->nome,nome) == 0){
            free(novo);
            return;
        }
        if(aux->next == NULL){
            aux->next = novo;
            return;
        }
        aux = aux->next;
    }
}
void quebraString(struct Node **head,char string[25000]){
    int i = 0, cont = 0;
    char nome[25];

    while(string[i] != '\0'){
        if(string[i] == ' '){
            if(cont > 0){
                nome[cont] = '\0';
                inserir(head, nome);
                cont = 0;
            }
            i++;
            continue;
        }
        else{
            nome[cont] = string[i];
            cont++;
            i++;
            continue;
        }
        
    }
    if(cont > 0){
        nome[cont] = '\0';
        inserir(head, nome);
    }
}
int contadorNo(struct Node *head){
    int cont = 0;
    while(head != NULL){
        cont++;
        head = head->next;
    }
    return cont;
}
void swap(struct Node **aux, struct Node **proximo){
    char temp[24];
    strcpy(temp, (*aux)->nome);
    strcpy((*aux)->nome, (*proximo)->nome);
    strcpy((*proximo)->nome, temp);
}
void bubblesort(struct Node **head){
    if(*head == NULL || (*head)->next == NULL){
        return;
    }
    int flag = 1;
    int n = 1;
    struct Node *aux = *head;
    int cont = contadorNo(aux);

    while(n <= cont && flag == 1){
        flag = 0;
        struct Node *aux = *head;
        struct Node *proximo = aux->next;
        for (int i = 0; i < cont - 1; i++){
            if(strcmp(aux->nome,proximo->nome) > 0){
                swap(&aux, &proximo);
                flag = 1;
            }
            aux = aux->next;
            proximo = proximo->next;
        }
        n++;
    }
}
void printar_e_excluir(struct Node **head){
    while(*head != NULL){
        struct Node *aux = *head;
        if((*head)->next == NULL){
            printf("%s", (*head)->nome);
            *head = (*head)->next;
            free(aux);
            return;
        }
        printf("%s ", (*head)->nome);
        *head = (*head)->next;
        free(aux);
    }
}
int main(){
    int casos;
    scanf("%d", &casos);
    for (int i = 0; i < casos; i++){
        struct Node *head = NULL;
        char string[25000];
        scanf(" %[^\n]", string);
        quebraString(&head,string);
        bubblesort(&head);
        printar_e_excluir(&head);
        printf("\n");
    }
    
    return 0;
}