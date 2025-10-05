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
    //ver se a head é null, se for retorna
    if(*head == NULL){
        strcpy(nomeVencedor, "");
        return;
    }  
    //ve se so tem uma criança, se sim retorna ela mesma
    if(*head == *tail){
        strcpy(nomeVencedor, (*head)->nome);
        free(*head);
        *head = NULL;
        *tail = NULL;
        return;
    }
    //contador para andar no circulo
    int casasAndar = (*head)->val;
    
    //define o lado que vai começar (horario ou anti-horario) a partir de ser par ou impar
    Node *aux = (casasAndar % 2 == 0) ? (*head)->prev : (*head)->next;
    
    //loop principal que elimina todas as crianças do circulo ate sobrar uma
    while(*head != *tail){
        // se for par, roda horario
        if(casasAndar % 2 == 0){
            int cont = 1;
            while (cont++ < casasAndar){
                aux = aux->prev;
            }
        }
        //se nao for par, roda anti horario
        else{
            int cont = 1;
            while (cont++ < casasAndar){
                aux = aux->next;
            }
        }
        //cria um ponteiro para a remoção e outros dois que vão representar o proximo e anterior
        Node *remover = aux;
        Node *next = aux->next;
        Node *prev = aux->prev;
        
        //seta o valor que ele irá andar no proximo loop e define o auxiliar para andar horario ou anti-horario a depender do valor
        //de casasAndar
        casasAndar = remover->val;
        aux = (casasAndar % 2 == 0) ? prev : next;
        
        //confere se o valor que vai ser removido parou na head ou na tail e trata
        if(remover == *head) *head = (*head)->next;
        if(remover == *tail) *tail = (*tail)->prev;

        //faz as ligações de prev e next, deixando remover de fora
        next->prev = prev;
        prev->next = next;
        //remove
        free(remover);
    }
    //após sobrar um unico no, coopia para um buffer de fora da função e remove o ultimo valor. seta tail e head para null
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