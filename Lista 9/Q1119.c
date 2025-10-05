#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node{
    int val;
    struct Node *next;
    struct Node *prev;
}Node;

void inserir_fim(Node **head, Node **tail, int val){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL) return;
    novo->val = val;

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

int main(){
    while(1){
        int N,k,m;
        if (scanf("%d %d %d",&N, &k, &m) != 3) return 0;
        if (N == 0 && k == 0 && m == 0){
            break;
        }

        Node *head = NULL;
        Node *tail = NULL;

        for (int i = 1; i <= N; i++){
            inserir_fim(&head, &tail, i);
        }
        Node *aux1 = head;
        Node *aux2 = tail;

        int total = N;
        int firstOut = 1;
        //loop principal para percorrer a lista circular de  acordo com o numero de elementos
        while (total > 0){
            //percorre ate encontrar o que vai ser removido andando pra frente
            int cont1 = 1;
            while (cont1 < k){
                aux1 = aux1->next; 
                cont1++;
            }
            Node *prev1 = aux1->prev;
            Node *next1 = aux1->next;
            Node *remover1 = aux1;

            //percorre ate encontrar o que vai ser removido andando pra tras
            int cont2 = 1;
            while (cont2 < m){
                aux2 = aux2->prev; 
                cont2++;
            }
            Node *prev2 = aux2->prev; 
            Node *next2 = aux2->next; 
            Node *remover2 = aux2;

            //se os que vão ser removidos cairem no mesmo valor entra nesse if
            if (remover1 == remover2){
                // printa o valor a ser removido nesse formato pedido pela questão
                printf("%s%3d", firstOut ? "" : ",", remover1->val);
                firstOut = 0;

                //verifica se o valor que vai ser removido é o ultimo, remove, trata os ponteiros e da o break no loop
                if (total == 1){
                    free(remover1);
                    head = NULL;
                    tail = NULL;
                    aux1 = NULL;
                    aux2 = NULL;
                    total = 0;
                    break;
                }
                //se não for o ultimo, verifica se o valor que sera removido vai ser a head ou a tail e trata os casos de avançar a head ou voltara a tail
                if (remover1 == head) head = next1;
                if (remover1 == tail) tail = prev1;

                //conecta o anterior do que sera removido ao proximo
                next1->prev = prev1; 
                prev1->next = next1;

                //atualiza o auxiliar que percorre a lista circular para o valor vizinho a depender do seu sentido (proximo e anterior)
                aux1 = next1;
                aux2 = prev1;

                //remove e decrementa o tamanho da lista circular
                free(remover1);
                total--;

                //se o que sobrou for o ultimo elemento, trata para apontar para si mesmo e a head ser igual a tail
                if (total == 1){
                    head->next = head;
                    head->prev = head;
                    tail = head;
                }
            }
            //se cairem os que serao removidos em valores diferentes vao para o else 
            else {
                // printa o valor a ser removido nesse formato pedido pela questão
                printf("%s%3d%3d", firstOut ? "" : ",", remover1->val, remover2->val);
                firstOut = 0;

                //verifica se o valor que sera removido vai ser a head ou a tail e trata os casos de avançar a head ou voltara a tail 
                if (remover1 == head) head = next1;
                if (remover1 == tail) tail = prev1;

                //conecta o anterior do que sera removido ao proximo
                next1->prev = prev1; 
                prev1->next = next1;

                //verifica se os que estão ao lado do segundo que vai ser removido é igual ao primeiro que vai ser removido, se for
                //altera para o next2 andar uma casa para frente e o prev2 andar uma casa para tras (caso um dos dois seja o mesmo endereço de memoria
                //do que se removido, ou seja, next2 == remover1 || prev2 == remover1)
                if (next2 == remover1) next2 = next1;
                if (prev2 == remover1) prev2 = prev1;

                //verifica se o valor que sera removido vai ser a head ou a tail e trata os casos de avançar a head ou voltara a tail
                if (remover2 == head) head = next2;
                if (remover2 == tail) tail = prev2;

                //conecta o anterior do que sera removido ao proximo
                next2->prev = prev2; 
                prev2->next = next2;
                
                //define o no que o aux1 vai começar(start1) que vai ser o proximo que do que vai ser removido e que o aux2 vai começar(start2)
                //que vai ser o anterior do que vai ser removido
                Node *start1 = next1;
                Node *start2 = prev2;
                
                //verifica se algum dos dois starts caiu em um no que vai ser removido. se sim, avança e/ou volta a depender do sentido que caiu
                if (start1 == remover2) start1 = next2;
                if (start2 == remover1) start2 = prev1;

                //remove os nos e decrementa o tamanho da lista
                free(remover1);
                free(remover2);
                total -= 2;

                //transforma os auxiliares que vão percorrer para os novos valores de start
                aux1 = start1;
                aux2 = start2;

                //se o que sobrou for o ultimo elemento, trata para apontar para si mesmo e a head ser igual a tail
                if (total == 1){
                    head->next = head;
                    head->prev = head;
                    tail = head;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
