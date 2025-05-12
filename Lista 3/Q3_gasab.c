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