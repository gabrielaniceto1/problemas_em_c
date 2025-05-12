#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char senha[35] = "amanda";
    int freq[128] = { 0 };

    for (int i = 0; senha[i] != '\0'; i++){
        freq[senha[i]]++;
    }
    
    for (int i = 0; i < 128; i++){
        if (freq[i] > 0){
            printf("freq: %d, char: %d\n", freq[i], i);
        }
    }
    
}
