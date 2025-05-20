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