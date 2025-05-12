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
