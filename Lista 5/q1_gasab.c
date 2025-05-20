/*
beecrowd | 1029
Fibonacci, Quantas Chamadas?
Por Neilor Tonin, URI  Brasil

Quase todo estudante de Ciência da Computação recebe em algum momento no início de seu curso de graduação algum problema envolvendo a sequência de Fibonacci. 
Tal sequência tem como os dois primeiros valores 0 (zero) e 1 (um) e cada próximo valor será sempre a soma dos dois valores imediatamente anteriores. 
Por definição, podemos apresentar a seguinte fórmula para encontrar qualquer número da sequência de Fibonacci:

fib(0) = 0
fib(1) = 1
fib(n) = fib(n-1) + fib(n-2);

Uma das formas de encontrar o número de Fibonacci é através de chamadas recursivas. 

Desta forma,
fib(4) = 1+0+1+1+0 = 3
Foram feitas 8 calls, ou seja, 8 chamadas recursivas.
Entrada
A primeira linha da entrada contém um único inteiro N, indicando o número de casos de teste. Cada caso de teste contém um inteiro X (1 ≤ X ≤ 39) .

Saída
Para cada caso de teste de entrada deverá ser apresentada uma linha de saída, no seguinte formato: fib(n) = num_calls calls = result, aonde num_calls é o 
número de chamadas recursivas, tendo sempre um espaço antes e depois do sinal de igualdade, conforme o exemplo abaixo.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fib(int x, int *cont);

int main(){
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){

        int x;
        scanf("%d", &x);

        int *cont = (int *)malloc(sizeof(int));

        *cont = -1;

        int result = fib(x, cont);

        printf("fib(%d) = %d calls = %d\n", x, (*cont), result);

        free(cont);
    }
    return 0;
}

int fib(int x, int *cont){

    (*cont)++;

    if (x == 0){
        return 0;
    }
    else if(x == 1){
        return 1;
    }
    else{
        return fib(x - 1, cont) + fib(x - 2, cont);
    }
}