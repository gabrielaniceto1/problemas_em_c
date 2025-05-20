/*

beecrowd | 1582
O Teorema de Pitágoras
Por Leandro Zatesko, UFFS BR Brasil

Pitágoras foi um matemático grego anterior a Euclides que viveu entre 570 e 495 a.C, considerado por Aristóteles como ‘o primeiro matemático’. 
Um dos mais antigos e mais importantes teoremas da História, o Teorema de Pitágoras estabelece que, em qualquer triângulo retângulo, 
o quadrado da hipotenusa é igual à soma dos quadrados dos catetos. 
O Teorema possui inúmeras aplicações, sendo a base de diversos resultados na Matemática, na Engenharia, na Física e na Ciência da Computação. 
Embora o Teorema leve o nome de Pitágoras, acredita-se que matemáticos ainda mais antigos, da Babilônia, já tivessem conhecimento da fórmula.

Diz-se que uma tripla de inteiros positivos (x, y, z) é uma tripla pitagórica se é possível existir um triângulo retângulo que tenha x, y e z como lados, 
independentemente da ordem em que os inteiros figurem na tripla. Por exemplos, (3, 4, 5), (6, 8, 10) e (5, 13, 12) são triplas pitagóricas, 
pois 52 = 32 + 42, 102 = 62 + 82 e 132 = 52 + 122. No entanto, a tripla (6, 8, 10) é apenas a tripla (3, 4, 5) multiplicada por 2, e, por isso, dizemos que 
(6, 8, 10) não é uma tripla pitagórica primitiva. 
Um tripla pitagórica (x, y, z) é dita primitiva se mdc(x, y, z) = 1. 
Euclides mostrou no século III a.C. que existem infinitas triplas pitagóricas primitivas.

Entrada
Cada linha da entrada é formada por 3 inteiros, x, y e z (1 ≤ x, y, z ≤ 104), separados entre si por um espaço em branco e fornecidos não necessariamente 
em ordem alguma, terminando em EOF.

Saída
Imprima para cada linha da entrada a linha “tripla pitagorica primitiva” (sem as aspas) se os inteiros dados formam uma tripla pitagórica primitiva,
“tripla pitagorica” se os inteiros dados formam uma tripla pitagórica não-primitiva, ou “tripla” se não formam uma tripla pitagórica.

*/

#include <stdio.h>
int hipo();

int mdc2();

int mdc3();

int main(){
    int a, b, c, maior;
    while(scanf("%d %d %d", &a, &b, &c) != EOF){

    maior = hipo(a, b, c);

    if (a == maior){
        if (maior * maior == (b * b) + (c * c)){
            if(mdc3(a, b, c) == 1){

                printf("tripla pitagorica primitiva\n");
            }
            else{
                printf("tripla pitagorica\n");
            }
        }
        else{
            printf("tripla\n");
        }

    }
    else if(b == maior){
        if (maior * maior == (a * a) + (c * c)){
            if(mdc3(a, b, c) == 1){

                printf("tripla pitagorica primitiva\n");
            }
            else{
                printf("tripla pitagorica\n");
            }
        }
        else{
            printf("tripla\n");
        }

    }
    else{
        if (maior * maior == (b * b) + (a * a)){
            if(mdc3(a, b, c) == 1){
            
                printf("tripla pitagorica primitiva\n");
            }
            else{
                printf("tripla pitagorica\n");
            }
        }
        else{
            printf("tripla\n");
        }

    }
}
    return 0;
}





int hipo(int a, int b, int c){


    if(a>b){
        if(a > c){
            
            return a;
        }
        else if(a < c){
            return c;
        }
    }
    else if (b>a)
    {
        if(b > c){
            
            return b;
        }
        else if(b < c){
           
            return c;
        }
    }
}


int mdc2(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mdc3(int a, int b, int c ){

    return mdc2(mdc2(a, b), c);
}