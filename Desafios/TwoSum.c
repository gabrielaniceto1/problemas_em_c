#include <stdio.h>
#include <stdlib.h>

// funciona para valores maior que 0
int *two_sum(int *arr, int arrSize, int target, int *answer){
    int bigger = 0;
    int smaller;
    for(int i = 0; i < arrSize; i++){
        if(i == 0) smaller = arr[i];
        if(arr[i] > bigger) bigger = arr[i];
        if(arr[i] < smaller) smaller = arr[i];
    }

    int hash[bigger + 1];
    for(int i = 0; i <= bigger; i++) hash[i] = 0;

    for(int i = 0; i < arrSize; i++){
        hash[arr[i]]++;
    }
    for (int i = 0; i < arrSize; i++){
        if(hash[arr[i]] > 0 && hash[target - arr[i]] > 0){
            if(arr[i] == target - arr[i] && hash[arr[i]] <= 1) continue;
            answer[0] = arr[i];
            answer[1] = target - arr[i];
            return answer;
        }
    }
    return answer;
}


int main() {
    int arr[] = {2, 7, 11, 15};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    int answer[2];

    int *res = two_sum(arr, arrSize, target, answer);

    printf("Resultado: %d e %d\n", res[0], res[1]);

    return 0;
}