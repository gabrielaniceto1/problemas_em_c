#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mdc(int a, int b);

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        int resultado = mdc(x, y);
        printf("%d\n", resultado);
    }
    return 0;
}
int mdc(int a, int b){
    if (b == 0) {
        return a; 
    } else {
        return mdc(b, a % b); 
    }
}