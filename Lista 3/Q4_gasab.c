/*
beecrowd | 1256
Tabelas Hash
Por Neilor Tonin, URI  Brasil

As tabelas Hash, também conhecidas como tabelas de dispersão, armazenam elementos com base no valor absoluto de suas chaves e em técnicas de 
tratamento de colisões. Para o cálculo do endereço onde deve ser armazenada uma determinada chave, 
utiliza-se uma função denominada função de dispersão, que transforma a chave em um dos endereços disponíveis na tabela.

Suponha que uma aplicação utilize uma tabela de dispersão com 13 endereços-base (índices de 0 a 12) e empregue a função de dispersão h(x) = x mod 13, em que 
x representa a chave do elemento cujo endereço-base deve ser calculado.

Se a chave x for igual a 49, a função de dispersão retornará o valor 10, indicando o local onde esta chave deverá ser armazenada. 
Se a mesma aplicação considerar a inserção da chave 88, o cálculo retornará o mesmo valor 10, ocorrendo neste caso uma colisão. 
O Tratamento de colisões serve para resolver os conflitos nos casos onde mais de uma chave é mapeada para um mesmo endereço-base da tabela. 
Este tratamento pode considerar, ou o recálculo do endereço da chave ou o encadeamento externo ou exterior.

O professor gostaria então que você o auxiliasse com um programa que calcula o endereço para inserções de diversas chaves em algumas tabelas, 
com funções de dispersão e tratamento de colisão por encadeamento exterior.

Entrada
A entrada contém vários casos de teste. A primeira linha de entrada contém um inteiro N indicando a quantidade de casos de teste. 
Cada caso de teste é composto por duas linhas. A primeira linha contém um valor M (1 ≤ M ≤ 100) que indica a quantidade de endereços-base na 
tabela (normalmente um número primo) seguido por um espaço e um valor C (1 ≤ C ≤ 200) que indica a quantidade de chaves a serem armazenadas. 
A segunda linha contém cada uma das chaves (com valor entre 1 e 200), separadas por um espaço em branco.

Saída
A saída deverá ser impressa conforme os exemplos fornecidos abaixo, onde a quantidade de linhas de cada caso de teste é determinada pelo valor de M. 
Uma linha em branco deverá separar dois conjuntos de saída.

*/

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