#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char nome[50];
    int idade;
    float notas[2];
    struct Aluno *next;
};

int main() {
    // Alocando memória para o aluno
    struct Aluno *aluno = (struct Aluno *) malloc(sizeof(struct Aluno));
    if (aluno == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Lendo dados
    printf("Digite o nome, idade e as duas notas do aluno: ");
    scanf("%49s %d %f %f", aluno->nome, &aluno->idade, &aluno->notas[0], &aluno->notas[1]);

    // Mostrando dados
    printf("\nAluno cadastrado:\n");
    printf("Nome: %s\n", aluno->nome);
    printf("Idade: %d\n", aluno->idade);
    printf("Notas: %.2f e %.2f\n", aluno->notas[0], aluno->notas[1]);

    // Liberando memória
    free(aluno);

    return 0;
}
