#include <stdio.h>
#include <stdlib.h>

// Estrutura da tabela com encadeamento por vetor (lista de int dinamicamente alocada)
struct Tabela {
    int *lista;
    int tamanho; // quantidade de elementos
};

int main() {
    int casos;
    scanf("%d", &casos);

    for (int c = 0; c < casos; c++) {
        int indices, numeros;
        scanf("%d %d", &indices, &numeros);

        // Vetor para armazenar as chaves
        int *chaves = (int *)malloc(numeros * sizeof(int));
        for (int i = 0; i < numeros; i++) {
            scanf("%d", &chaves[i]);
        }

        // Inicializando a tabela hash
        struct Tabela *tabela = (struct Tabela *)malloc(indices * sizeof(struct Tabela));
        for (int i = 0; i < indices; i++) {
            tabela[i].lista = NULL;
            tabela[i].tamanho = 0;
        }

        // Inserindo as chaves na tabela hash
        for (int i = 0; i < numeros; i++) {
            int pos = chaves[i] % indices;
            tabela[pos].tamanho++;
            tabela[pos].lista = (int *)realloc(tabela[pos].lista, tabela[pos].tamanho * sizeof(int));
            tabela[pos].lista[tabela[pos].tamanho - 1] = chaves[i];
        }

        // Imprimindo o resultado
        for (int i = 0; i < indices; i++) {
            printf("%d ->", i);
            for (int j = 0; j < tabela[i].tamanho; j++) {
                printf(" %d ->", tabela[i].lista[j]);
            }
            printf(" \\\n");
        }

        // Imprimir linha em branco entre os casos (exceto no último)
        if (c < casos - 1) {
            printf("\n");
        }

        // Liberar memória
        for (int i = 0; i < indices; i++) {
            free(tabela[i].lista);
        }
        free(tabela);
        free(chaves);
    }

    return 0;
}
