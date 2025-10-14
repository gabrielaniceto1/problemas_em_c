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
void liberarLista(Node **head){
    if (*head == NULL) return;
    while(*head != NULL){
        Node *aux = *head;
        *head = (*head)->next;
        free(aux);
    }
    *head = NULL;
}
int contar_criticos(Node *head) {
    int criticos = 0;
    int inicio_atendimento = 7 * 60;
    Node *paciente = head;
    while (paciente != NULL) {
        while (inicio_atendimento < paciente->tempoTotal) {
            inicio_atendimento += 30;
        }
        int tempo_espera = inicio_atendimento - paciente->tempoTotal;
        if (tempo_espera > paciente->tempoCritico) {
            ++criticos;
        }
        inicio_atendimento += 30;
        paciente = paciente->next;
    }
    return criticos;
}
int main(){
    int pacientes;
    while(scanf("%d", &pacientes) != EOF){
        Node *head = NULL;

        if(pacientes == 0) break;
 
        int criticos = 0;
        int tempoAtual = 7 * 60;

        for (int i = 0; i < pacientes; i++){
            int h, m, c;
            scanf("%d %d %d", &h, &m, &c);
            inserir_final(&head, h, m, c);
        }
        criticos = contar_criticos(head);
        liberarLista(&head);
        printf("%d\n", criticos);
    }
    return 0;
}