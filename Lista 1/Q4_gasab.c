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