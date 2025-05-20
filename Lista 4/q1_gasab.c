/*
beecrowd | 2136
Amigos do Habay
Por Joao Marcos Salvanini Bellini de Moraes, IFSULDEMINAS BR Brazil

Todo final de ano ocorre uma festa na Instituição de Educação Fantástica (IEF). Logo no início de julho, são abertas as inscrições para participar dela. 
No momento da inscrição, o usuário pode escolher se quer ser "O Amigo do Habay" na festa ou não. 
O mais lógico seria escolher a opção Sim, afinal, é um privilégio ser O Amigo do Habay, já que ele é a pessoa mais descolada do IEF. 
Porém, há indivíduos que definitivamente não pretendem ser O Amigo do Habay, e por motivos desconhecidos.

Somente um será o escolhido. Em vista disso, muitos alunos que escolheram a opção Sim realizaram a inscrição diversas vezes para aumentar a própria 
probabilidade de ser O Amigo do Habay. O organizador geral da festa contratou você para organizar as inscrições do site, pois está havendo um spam de inscrições. 
O critério para ser o escolhido é a quantidade de letras do primeiro nome, e em caso de empate, vence aquele que realizou primeiro a inscrição. 
A organização final dos inscritos deverá seguir a ordem de escolha (Sim ou Não), mas respeitando a ordem alfabética.

OBS.: Ninguém que escolheu a opção Não realizou a inscrição mais de uma vez.

Entrada
A entrada contém somente um caso de teste. 
Cada linha é composta pelo primeiro nome do participante (sem espaços), seguido da opção YES (caso o usuário queira ser O Amigo do Habay) ou 
NO (caso não queira). A entrada termina assim que o usuário digita "FIM" (sem as aspas).

Saída
Seu programa deverá imprimir os inscritos pela ordem de escolha e por ordem alfabética, seguido do nome do vencedor. 
Imprima uma linha em branco entre a lista de inscritos e o nome do vencedor.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Amigos {
    char nome[21];
    int ordem;
    struct Amigos *next;
};

void append_ordenado(struct Amigos **head, char nome[21], int cont);

void maior_nome(struct Amigos *head);

void show(struct Amigos *head);

int main() {
    char end[4]="FIM";
    struct Amigos *head = NULL;
    struct Amigos *headNegativo = NULL;
    int cont1 = 0, cont2 = 0;
    while (1){
        char def[4], nome[21];
        scanf("%s", nome);
        if(strcmp(nome,end) == 0){
            break;
        }
        scanf("%s", def);
    
        if (strcmp(def, "YES") == 0){
            cont1++;
            append_ordenado(&head, nome, cont1);
        }
        else{
            cont2++;
            append_ordenado(&headNegativo, nome, cont2);
        }
        
        
    }
    
    show(head);
    show(headNegativo);
    printf("\n");
    maior_nome(head);

     while (head != NULL) {
         struct Amigos *temp = head;
         head = head->next;
         free(temp);
     }
     while (headNegativo != NULL) {
        struct Amigos *temp = headNegativo;
         headNegativo = headNegativo->next;
         free(temp);
    }


    return 0;
}

void append_ordenado(struct Amigos **head, char nome[21], int cont) {
    struct Amigos *novo = (struct Amigos *)malloc(sizeof(struct Amigos));
    strcpy(novo->nome, nome);
    novo->ordem = cont;
    novo->next = NULL;

    if (*head == NULL || strcmp(nome, (*head)->nome) < 0) {
        novo->next = *head;
        *head = novo;
        return;
    }

    struct Amigos *atual = *head;
    while (atual->next != NULL && strcmp(nome, atual->next->nome) > 0) {
        atual = atual->next;
    }

    novo->next = atual->next;
    atual->next = novo;
}

void show(struct Amigos *head) {
    struct Amigos *aux = (struct Produto *)malloc(sizeof(struct Amigos));
    while (head != NULL) {
        if(strcmp(head->nome, aux->nome) != 0){
            printf("%s\n", head->nome);
        }
        aux = head;
        head = head->next;
    }
}

void maior_nome(struct Amigos *head) {
    if (head == NULL) return;

    struct Amigos *maior = head;

    while (head != NULL) {
        size_t tam_atual = strlen(head->nome);
        size_t tam_maior = strlen(maior->nome);

        if (tam_atual > tam_maior || 
            (tam_atual == tam_maior && head->ordem < maior->ordem)) {
            maior = head;
        }
        head = head->next;
    }

    printf("Amigo do Habay:\n%s\n", maior->nome);
}