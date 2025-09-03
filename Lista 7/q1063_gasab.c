Conversation opened. 1 unread message.

Skip to content
Using CESAR School Mail with screen readers

2 of 2,850
codigo q2
Inbox

AMANDA LUZ CHAVES <alc2@cesar.school>
Attachments
11:54 AM (1 hour ago)
to me


 One attachment
  •  Scanned by Gmail
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Node{
    char caracter;
    struct Node *next;
};

void inserirPilha(struct Node **head, char caracter){
    struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
    if(novo == NULL) return;
    novo->caracter = caracter;
    novo->next = *head;
    *head = novo;
}
void remover_pilha(struct Node **head){
    struct Node *aux = *head;
    *head = (*head)->next;
    free(aux);
}
int main(){
    struct Node *head = NULL;
    int cont = -1;
    while(1){
        scanf("%d", &cont);
        if(cont == 0) break;

        char desordenado[27], ordenado[27];
        for(int i = 0; i <  cont; i++){
            scanf(" %c", &desordenado[i]);
        }
        desordenado[cont] = '\0';
        for (int i = 0; i < cont; i++){
            scanf(" %c", &ordenado[i]);
        }
        ordenado[cont] = '\0';

        char operacoes[64];
        operacoes[0] = '\0';

        int i_ordenado = 0;
        int i_desordenado = 0;

        while(i_ordenado < cont){
            while((head == NULL || head->caracter != ordenado[i_ordenado]) && i_desordenado < cont){
                inserirPilha(&head, desordenado[i_desordenado]);
                i_desordenado++;
                strcat(operacoes, "I");
            }
            if(head != NULL && head->caracter == ordenado[i_ordenado]){
                remover_pilha(&head);
                i_ordenado++;
                strcat(operacoes, "R");
            }
            else{
                strcat(operacoes, " Impossible");
                break;
            }
        }
        printf("%s\n", operacoes);
        while(head != NULL){
            struct Node *aux = head;
            head = head->next;
            free(aux);
        }
        
    }
    return 0;
}
q2.c
Displaying q2.c.