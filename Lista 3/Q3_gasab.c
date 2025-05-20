/*
beecrowd | 2466
Sinuca
Por OBI - Olimpíada Brasileira de Informática 2014 BR Brazil

Nadine e Celine inventaram um passatempo com bolas de sinuca, pretas e brancas, que são colocadas uma por vez na mesa, de acordo com uma regra fixa. 
Agora elas estão tentando descobrir, com um computador, a cor da bola que vai ser colocada por último! Você pode ajuda-las?

Funciona assim. 
No início, são colocadas N bolas formando a primeira fileira. Em seguida, um triângulo equilátero é formado, fileira a fileira, de acordo com a seguinte regra. 
Ao se colocar uma bola na nova fileira, ela ficará encostada em duas bolas da fileira anterior e sua cor será:

Preta, se estiver encostada em duas bolas de mesma cor;
Branca, se estiver encostada em duas bolas de cores diferentes.
A figura abaixo ilustra a formação de um triângulo para N = 5.

Nesta tarefa, você deve escrever um programa que, dadas as cores das bolas da primeira fileira, descubra qual é a cor da bola que será colocada por último. 
Na figura, foi uma bola branca!

Entrada
A entrada é composta por duas linhas. 
A primeira linha contém um inteiro N (2 ≤ N ≤ 64), o número de bolas da primeira fileira. 
A segunda linha contém N inteiros representando as cores das bolas da primeira fileira. 
Se a bola é preta, o número será “1”, se for branca, será “-1”.

Saída
Seu programa deve imprimir uma linha contendo a palavra “preta”, se a última bola for preta; ou a palavra “branca”, se for branca.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1 - preta ; -1 - branca
int main(){
    int n;
    scanf("%d", &n);

    int *p;
    p = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }
    while (n > 1){
        int *q;
        q = (int*)malloc((n - 1) * sizeof(int));

        for (int i = 0; i < n - 1; i++){
            if (p[i] == p[i + 1]){
                q[i] = 1;
            }
            else{
                q[i] = -1;
            }
        }
        free(p);
        p = q;
        n--;
    }
    if (p[0] == 1){
        printf("preta\n");
    }
    else{
        printf("branca\n");
    }
    free(p);

    return 0;
}