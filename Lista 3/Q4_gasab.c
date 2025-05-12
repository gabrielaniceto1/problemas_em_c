#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//OBS - Fazer uma matriz de inteiros com alocação dinâmica, usando realloc para cada
//inserção na linha da matriz.

struct Tabela
{
    int *lista;
    int tamanho;
};


int main(){
    int casos;
    scanf("%d", &casos);
    for (int j = 0; j < casos; j++){
        int indices, numeros, *chaves;
        scanf("%d %d", &indices, &numeros);
        
        chaves = (int*) malloc(numeros * sizeof(int));

        for (int i = 0; i < numeros; i++){
            scanf("%d", &chaves[i]);
        }
        struct Tabela *tabelas = (struct Tabela *)malloc(indices * sizeof(struct Tabela));
        for (int i = 0; i < indices; i++){
                    tabelas[i].lista = NULL;
                    tabelas[i].tamanho = 0;  
        }
        for (int i = 0; i < numeros; i++){
            int def = chaves[i] % indices;
            tabelas[def].tamanho++;
            tabelas[def].lista = (int*) realloc(tabelas[def].lista, tabelas[def].tamanho*sizeof(int));
            tabelas[def].lista[tabelas[def].tamanho - 1] = chaves[i];
        }
        for (int i = 0; i < indices; i++){
            printf("%d ->", i);
            for(int k = 0; k < tabelas[i].tamanho; k++){
            printf(" %d ->", tabelas[i].lista[k]);
            }
            printf(" \\\n");
        }
        
        if (j < casos - 1) {
            printf("\n");
        }

        for (int i = 0; i < indices; i++) {
            free(tabelas[i].lista);
        }
        free(tabelas);
        free(chaves);
        
        
    }
    
    return 0;
}