#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node{
    int tempoCritico;
    int tempoLimite;
    int tempoTotal;
    struct Node *next;
    struct Node *prev;
}Node;

void inserir_final(Node **head, int hora, int minuto, int tempoCritico){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) return;

    hora = hora * 60;

    novo->tempoTotal = hora + minuto;
    novo->tempoCritico = tempoCritico;
    novo->tempoLimite = novo->tempoTotal + tempoCritico;

    novo->next = NULL;
    novo->prev = NULL;

    if(*head == NULL){
        *head = novo;
        return;
    }
    Node *aux = *head;
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = novo;
    novo->prev = aux;
}
void proximoAtendimento(Node **head, int *criticos, int *tempoAtual){
    if (*head == NULL) return;

    Node *paciente = *head;
    int chegada = paciente->tempoTotal;
    int inicio;

    if (chegada >= *tempoAtual) {
        inicio = chegada;
    } else {
        int m = (*tempoAtual) % 60;
        if (m == 0 || m == 30) {
            inicio = *tempoAtual;
        } else if (m < 30) {
            inicio = *tempoAtual + (30 - m);
        } else {
            inicio = *tempoAtual + (60 - m);
        }
    }

    if (inicio > paciente->tempoLimite) {
        (*criticos)++;
    }

    *tempoAtual = inicio + 30;

    Node *aux = *head;
    *head = (*head)->next;
    if (*head) (*head)->prev = NULL;
    free(aux);
}
int main(){
    int pacientes;
    while(1){
        Node *head = NULL;

        if (scanf("%d", &pacientes) != 1) break;
        if(pacientes == 0) break;
 
        int criticos = 0;
        int tempoAtual = 7 * 60;

        for (int i = 0; i < pacientes; i++){
            int h, m, c;
            scanf("%d %d %d", &h, &m, &c);
            inserir_final(&head, h, m, c);
        }
        for (int i = 0; i < pacientes; i++){
            proximoAtendimento(&head, &criticos, &tempoAtual);
        }
        printf("%d\n", criticos);
    }
    return 0;
}