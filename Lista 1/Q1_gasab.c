#include <stdio.h>

int main(){
    int n = 0, x = 0;

    scanf("%d", &n);
    int arr[n];

    for (int i =0; i < n; i++){
        scanf("%d", &arr[i]);
        if (i > 0){
            if (arr[i] < arr[i - 1]){
            x = i + 1;
            break;
        }
    }
    }
    printf("%d\n", x);

    return 0;
}