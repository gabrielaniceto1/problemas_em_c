#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    int casos;
    char idioma[20];

    scanf("%d", &casos);

    char arr[casos][20];

    for(int i = 0; i < casos; i++){

        int pessoas=0;

        scanf("%d", &pessoas);

        for (int j = 0; j < pessoas; j++)
        {

            char temp[20];
            scanf("%s", temp);

            if(j==0){
                strcpy(idioma,temp);
            }
            else if(strcmp(idioma,temp) == 0 && j == pessoas - 1){
                strcpy(arr[i],idioma);
            }
            else if(strcmp(idioma, temp) != 0 && j>0){
                strcpy(arr[i],"ingles");
            }
        }
        
    }
    for(int i=0;i<casos;i++){
    printf("%s\n", arr[i]);
    }
    
    return 0;
}