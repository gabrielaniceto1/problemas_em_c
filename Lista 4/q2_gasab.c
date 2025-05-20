/*
beecrowd | 2479
Ordenando a Lista de Crianças do Papai Noel
Por Cristian J. Ambrosi, URI BR Brazil

Papai Noel está nos preparativos finais para a entrega dos presentes para as crianças do mundo todo pois o natal está chegando mais uma vez. 
Olhando suas novas listas de crianças que irão ganhar presentes neste ano ele percebeu que o duende 
estagiário (que havia ficado responsável por fazer as listas) não havia colocado os nomes em ordem alfabética.

Como o Papai Noel é um homem muito organizado ele deseja que cada lista de crianças possua, no seu final, o total de crianças que foram bem comportadas 
neste ano e um total das que não foram. Assim ele pode comparar a quantidade de crianças que se comportam este ano com as dos anos anteriores.

Para ajudar o bom velhinho, seu dever é criar um programa que leia todos os nomes da lista e imprima os mesmos nomes em ordem alfabética. 
No final da lista, você deve imprimir o total de crianças que foram e não foram comportadas neste ano.

Entrada
A entrada é composta por vários nomes. O primeiro valor N (0 ≤ N ≤ 100), indica quantos nomes tem na lista. 
As N linhas seguintes, contem um caracter especial correspondente ao comportamento da criança (+ indica que a criança foi bem comportada, 
- indica que a criança não foi bem comportada). Após o caracter especial, segue o nome da criança com no máximo 20 caracteres.

Saída
Para cada lista de crianças, você deve imprimir os nomes em ordem alfabética. Após imprimir os nomes das crianças, você deve mostrar o total de crianças que 
se comportaram bem ou mal durante o ano.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Criancas {
    char nome[21];
    char sinal;
    struct Criancas *next;
};

void append_ordenado(struct Criancas **head, char nome[21], char sinal);

void show(struct Criancas *head);

int main() {
    int n;
    scanf("%d", &n);

    struct Criancas *head = NULL;
    int contMenos=0, contMais=0;
    for (int i = 0; i < n; i++) {
        char nome[21], sinal;
        scanf(" %c %s", &sinal, nome);
        append_ordenado(&head, nome, sinal);
        if(sinal == '-') contMenos++;
        else contMais++;
    }

    show(head);
    printf("Se comportaram: %d | Nao se comportaram: %d\n", contMais, contMenos);

    while (head != NULL) {
        struct Criancas *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

void append_ordenado(struct Criancas **head, char nome[21], char sinal) {
    struct Criancas *novo = (struct Criancas *)malloc(sizeof(struct Criancas));
    strcpy(novo->nome, nome);
    novo->sinal = sinal;
    novo->next = NULL;

    if (*head == NULL || strcmp(nome, (*head)->nome) < 0) {
        novo->next = *head;
        *head = novo;
        return;
    }

    struct Criancas *atual = *head;
    while (atual->next != NULL && strcmp(nome, atual->next->nome) > 0) {
        atual = atual->next;
    }

    novo->next = atual->next;
    atual->next = novo;
}

void show(struct Criancas *head) {
    while (head != NULL) {
        printf("%s\n", head->nome);
        head = head->next;
    }
}
