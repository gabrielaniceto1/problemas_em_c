#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int josephus(int n, int k);

int main(){
    int nc;
    scanf("%d", &nc);
    for (int i = 0; i < nc; i++){
        int n, k;
        scanf("%d %d", &n, &k);

        int ultima_pessoa;
        ultima_pessoa = josephus(n, k) + 1;

        printf("Case %d: %d\n", (i+1), ultima_pessoa);
    }
    
    return 0;
}
int josephus(int n, int k){
    if (n == 1)
        return 0;
    else
        return (josephus(n - 1, k) + k) % n;
}