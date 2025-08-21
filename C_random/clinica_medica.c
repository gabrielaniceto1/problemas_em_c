#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char nome[30];
    struct Node *next;
};

void inserir_fila(struct Node **head, struct Node **tail, char *nome){
    struct Node *novo = (struct Node*)malloc(sizeof(struct Node));
    if(novo == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
    }
    strcpy(novo->nome, nome);
    novo->next = NULL;
    if(*head == NULL){
        *head = novo;
        *tail = novo;
    }
    else{
        (*tail)->next = novo;
        *tail = novo;
    }
    printf("Paciente cadastrado com sucesso!\n");
}

void remover_fila(struct Node **head, struct Node **tail){
    struct Node *aux = (*head);
    if(aux == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
    }
    if(*head == NULL){
        printf("Não há ninguem para ser atendido!\n");
        return;
    }
    else{
        (*head) = (*head)->next;
        free(aux);

        if(*head == NULL){
            *tail = NULL;
        }
    }
    printf("Atendimento realizado com sucesso!");
}

void consultar_fila(struct Node *head){
    int count = 1;
    char nome[30];

    if(head == NULL){
        printf("Não há pacientes!\n");
    }
    else{
        printf("Digite o nome do paciente que você quer procurar:\n");
        scanf(" %s", nome);

        while(head != NULL && strcmp(head->nome, nome) != 0 ){
            head = head->next;
            count++;
        }
        if(head == NULL){
            printf("Paciente não encontrado!\n");
        }
        else{
            printf(" Paciente: %s ; ordem: %d \n", nome, count);
        }
    }
}
int main(){
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int cont = 0;

    while(1){
        printf("Clínica Médica\n\n=============\n\n(1) Incluir paciente\n\n(2) Realizar atendimento do paciente (remoção do paciente)\n\n(3) Consultar a posição atual do paciente pelo nome\n\n(4) Exibir a quantidade de pacientes já atendidos\n\n(5) Sair\n\n");
        int opcao;
        scanf(" %d", &opcao);
        if(opcao == 1){
            char nome[30];
            printf("Digite o nome do paciente: \n");
            scanf(" %29[^\n]", nome);
            inserir_fila(&head, &tail, nome);
        }
        else if(opcao == 2){
            remover_fila(&head, &tail);
            cont++;
        }
        else if(opcao == 3){
            consultar_fila(head);
        }
        else if(opcao == 4){
            printf(" %d usuarios atendidos\n", cont);
        }
        else if(opcao == 5){
            printf("Fechando programa ...\n");
            while(head != NULL){
                struct Node *aux = head;
                head = head->next;
                free(aux);
            }
            tail = head;
            break;
        }
        else{
            printf("Digite uma opção valida!\n");
        }
    }
    return 0;
}