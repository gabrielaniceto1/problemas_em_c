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
