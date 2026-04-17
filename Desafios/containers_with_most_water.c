#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int maxArea(int* height, int heightSize) {
    if(heightSize < 2) return 0;

    int idx1 = 0;
    int idx2 = heightSize - 1;
    int max = 0;

    while(idx1 < idx2){
        int w = idx2 - idx1;
        int h = height[idx1] < height[idx2] ? height[idx1] : height[idx2];
        int area = w * h;

        if(area > max) max = area;

        if(height[idx1] < height[idx2]){
            idx1++;
        }
        else{
            idx2--;
        }
    }
    return max;
}

int main() {
    int height1[] = {1,8,6,2,5,4,8,3,7};
    int size1 = sizeof(height1) / sizeof(height1[0]);

    int height2[] = {1,1};
    int size2 = sizeof(height2) / sizeof(height2[0]);

    int height3[] = {4,3,2,1,4};
    int size3 = sizeof(height3) / sizeof(height3[0]);

    int height4[] = {1,2,1};
    int size4 = sizeof(height4) / sizeof(height4[0]);

    printf("Teste 1: %d\n", maxArea(height1, size1)); // 49
    printf("Teste 2: %d\n", maxArea(height2, size2)); // 1
    printf("Teste 3: %d\n", maxArea(height3, size3)); // 16
    printf("Teste 4: %d\n", maxArea(height4, size4)); // 2

    return 0;
}