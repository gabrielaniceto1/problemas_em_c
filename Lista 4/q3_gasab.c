/*
beecrowd | 2381
Lista de Chamada
Por OBI - Olimpíada Brasileira de Informática 2010 BR Brazil

Tia Joana é uma respeitada professora e tem vários alunos. 
Em sua última aula, ela prometeu que iria sortear um aluno para ganhar um bônus especial na nota final: ela colocou N pedaços de papel numerados de 1 a N 
em um saquinho e sorteou um determinado número K; o aluno premiado foi o K-ésimo aluno na lista de chamada.

O problema é que a Tia Joana esqueceu o diário de classe, então ela não tem como saber qual número corresponde a qual aluno. 
Ela sabe os nomes de todos os alunos, e que os números deles, de 1 até N, são atribuídos de acordo com a ordem alfabética, mas os alunos dela estão muito 
ansiosos e querem logo saber quem foi o vencedor.

Dado os nomes dos alunos da Tia Joana e o número sorteado, determine o nome do aluno que deve receber o bônus.

Entrada
A primeira linha contém dois inteiros N e K separados por um espaço em branco (1 ≤ K ≤ N ≤ 100). 
Cada uma das N linhas seguintes contém uma cadeia de caracteres de tamanho mínimo 1 e máximo 20 representando os nomes dos alunos. 
Os nomes são compostos apenas por letras minúsculas de 'a' a 'z'.

Saída
Seu programa deve imprimir uma única linha, contendo o nome do aluno que deve receber o bônus.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alunos {
    char nome[21];
    struct Alunos *next;
};

void append_ordenado(struct Alunos **head, char nome[21]);

void show(int k, struct Alunos *head);

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    struct Alunos *head = NULL;

    for (int i = 0; i < n; i++) {
        char nome[21];
        scanf("%s", nome);
        append_ordenado(&head, nome);
    }

    show(k, head);

    while (head != NULL) {
        struct Alunos *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

void append_ordenado(struct Alunos **head, char nome[21]) {
    struct Alunos *novo = (struct Alunos *)malloc(sizeof(struct Alunos));
    strcpy(novo->nome, nome);
    novo->next = NULL;

    if (*head == NULL || strcmp(nome, (*head)->nome) < 0) {
        novo->next = *head;
        *head = novo;
        return;
    }

    struct Alunos *atual = *head;
    while (atual->next != NULL && strcmp(nome, atual->next->nome) > 0) {
        atual = atual->next;
    }

    novo->next = atual->next;
    atual->next = novo;
}

void show(int k, struct Alunos *head) {
    int count = 1;
    while (head != NULL && count < k) {
        head = head->next;
        count++;
    }

    if (head != NULL)
        printf("%s\n", head->nome);
    else
        printf("Posição inválida.\n");
}
