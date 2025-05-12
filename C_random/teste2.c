#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char ch;
    int freq;
} Cfreq;

void swap(Cfreq* a, Cfreq* b){
    Cfreq temp = *a;
    *a = *b;
    *b = temp;
}

int main (){
    int count = 0;
    char senha[1000];
    while(scanf(" %[^\n]", senha) != EOF){
        Cfreq freq[128] = { 0 };

        for (int i = 0; senha[i] != '\0'; i++){
            freq[senha[i]].freq++;
            freq[senha[i]].ch = senha[i];
        }
        
        for (int i = 0; i < 128; i++){
            for (int j = 0; j < 128; j++){
                if (freq[i].freq < freq[j].freq || (freq[i].freq == freq[j].freq && freq[i].ch > freq[j].ch)){
                    swap(&freq[i], &freq[j]);
                }
            }
        }

        if (count++ > 0)
            printf("\n");
        
        for (int i = 0; i < 128; i++){
            if (freq[i].freq > 0){
                printf("%d %d\n", freq[i].ch, freq[i].freq);
            }
        }  
    }

    return 0;
}
