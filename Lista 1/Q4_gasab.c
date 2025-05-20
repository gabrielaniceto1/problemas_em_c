/*
Existem n pessoas que estão em uma linha, em um famoso jogo chamado "contando". 
Quando o jogo começa, a pessoa mais à esquerda diz "1" em voz alta, em seguida, a segunda pessoa 
(as pessoas estão numerados de 1 a n, da esquerda para a direita) diz "2" em voz alta. 
Isto é seguido pela terceira pessoa dizendo "3", e assim por diante. 
Quanda o e-nésima pessoa (ou seja, a pessoa mais a direita) diz "n" em voz alta, a próxima vez vai para a sua pessoa imediatamente à esquerda 
(ou seja, a (n - 1)-nésima pessoa), que deve dizer "n + 1" em voz alta, então a (n - 2)-ésima pessoa deve dizer "n + 2 " em voz alta. 
Depois que a pessoa mais à esquerda falou de novo, a contagem vai para a direita novamente. Há um senão (caso contrário, o jogo seria muito chato!): 
Se uma pessoa dizer um número que é múltiplo de 7, ou sua representação decimal contém o dígito 7, ele deve bater palmas em vez disso! 
A tabela a seguir nos mostra o processo de contagem para n = 4 ('X' representa uma salva de palmas). Quando a 3ª pessoa bate palmas pela 4 vez, 
ele está realmente contando 35.

Person	1	2	3	4	3	2	1	2	3
Action	1	2	3	4	5	6	X	8	9
Person	4	3	2	1	2	3	4	3	2
Action	10	11	12	13	X	15	16	X	18
Person	1	2	3	4	3	2	1	2	3
Action	19	20	X	22	23	24	25	26	X
Person	4	3	2	1	2	3	4	3	2
Action	X	29	30	31	32	33	34	X	36
Dado n, m e k, a sua tarefa é descobrir, quando a m-ésima pessoa bate palmas pela k-ésima vez, e qual é o número real que está sendo contado.

Entrada
Haverá, no máximo, 100 casos de teste na entrada. Cada teste contém três inteiros n, m e k (2 ≤ n ≤ 100, 1 ≤ m ≤ n, 1 ≤ k ≤ 100) em uma única linha. 
O último caso de teste é seguido por uma linha com n = m = k = 0, e que não deverá ser processada.

Saída
Para cada linha, imprima o número real que está sendo contado, quando a m-ésima pessoa bate palmas pela k-ésima vez. 
Se isso nunca pode acontecer, imprima '-1'.

*/

#include <stdio.h>

int sete(int i);

int classificacao(int n, int m, int k);

int main(){
    int n = 0, m = 0, k = 0, var = 0;

    while(1){

        scanf("%d %d %d", &n, &m, &k);

        if(n == 0 && m == 0 && k == 0 ){
            break;
        }
        else{
            if (n > 100 || m > 100 || k > 100){
                return -1;
            }
            else{
            var = classificacao(n, m, k);
            printf("%d\n", var);
            }
        }
    }
    return 0;
}

int sete(int i){
    while (i > 0) {
        if (i % 10 == 7) return 0;
        i /= 10;
    }
    return 1;
}
int classificacao(int n, int m, int k){
    int cont1 = 1, cont2 = 1, cont3 = 1, cont4 = 0, arr[100]= {0};

    while(1){
        if (cont2 == m){
            if (cont4 == k){
                return arr[cont4 - 1];
            }
        }
        if(cont1 % 7 == 0 || sete(cont1) == 0){
            if (cont2 == m){
                    arr[cont4] = cont1;
                    cont4++; 
            }
        }
        if(cont2 == n){
            cont3 = -1;
        }
        else if (cont2 == 1 && cont3 == -1){
            cont3 = 1;
        }
        cont2 += cont3;
        cont1++;
    }

    return -1;
}