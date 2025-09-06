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
        return;
    }
    struct Node *aux = *head;
    while(aux != NULL){
        if(strcmp(aux->nome,nome) == 0){
            free(novo);
            return;
        }
        if(aux->next == NULL){
            break;
        }
        aux = aux->next;
    }
    aux->next = novo;
}
void quebra_string(struct Node **head, char string[21001]){
    int i = 0;
    char nome[21];
    nome[20] = '\0';

    while(string[i] != '\0'){
        int k = 0;
        for(int j = i; j < i + 20;j++){
            if(string[j] == ' ' || string[j] == '\0'){
                nome[j - i] = '\0';
                append(head, nome);
                k = j; 
                break;
            }
            else{
                nome[j - i] = string[j];
            }
        }
        while(string[k] != ' ' &&  string[k] != '\0'){
            k++;
        }
        if(string[k] == ' '){
            i = k + 1;
        }
        else{
            i = k;
        }         
    }    
}
void bubblesort(struct Node **head){
    int troca = 1;
    int cont = 0, cont2 = 1;
    struct Node *contador = *head;
    while (contador){
        cont++;
        contador = contador->next;
    }

    while (cont2 <= cont && troca == 1) {
        troca = 0;
        struct Node *prev = NULL;
        struct Node *aux  = *head;

        for (int i = 0; i < cont - 1; i++) {
            struct Node *temp = aux->next;
            if(strcmp(aux->nome, temp->nome) > 0){
                aux->next  = temp->next;
                temp->next = aux;

                if(prev != NULL){
                    prev->next = temp;
                }
                else{
                    *head = temp;
                }
                prev = temp;
                troca = 1;
            }
            else{
                prev = aux;
                aux  = aux->next;
            }
        }
        cont2++;
    }
}
int main(){
    struct Node *head = NULL;
    int casos;
    int first = 1;
    scanf("%d", &casos);
    for( int i = 0; i < casos;i++){
        char string[21001];
        scanf(" %21000[^\n]", string);
        quebra_string(&head, string);
        bubblesort(&head);
        while(head != NULL){
            struct Node *garbage = head;
            if (!first) putchar(' ');
            printf("%s", head->nome);
            head = head->next;
            free(garbage);
            first = 0;
        }
        printf("\n");
    }
    return 0;
}