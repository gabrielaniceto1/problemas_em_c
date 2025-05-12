#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Morador {
    int hora;
    int minutos;
    char nome[101];
    };

void swap(char **a, char **b);
void swapInt(int *a, int *b);
int converter(int h, int m);
int conferir(int total, int p);

int main(){
    int p, q;
    scanf("%d %d", &p, &q);

    struct Morador moradores[q];

    for (int i = 0; i < q; i++){
        char horario[6];
        scanf("%s %s", horario, moradores[i].nome);
        char hora[3], minuto[3];

        hora[0] = horario[0];
        hora[1] = horario[1];
        hora[2] = '\0';

        minuto[0] = horario[3];
        minuto[1] = horario[4];
        minuto[2] = '\0';

        moradores[i].hora = atoi(hora);
        moradores[i].minutos = atoi(minuto);  
    }

    int *array_total = NULL, cont = 0;
    char **array_nome = NULL;

    array_nome = (char**)malloc(q*sizeof(char*));
    array_total = (int*)malloc(q*sizeof(int));

    for (int i = 0; i < q; i++){
        int total = converter(moradores[i].hora, moradores[i].minutos);
        if(conferir(total, p) == 1){
            array_nome[cont] = (char*)malloc((strlen(moradores[i].nome) + 1) * sizeof(char));
            strcpy(array_nome[cont],moradores[i].nome);
            array_total[cont] = total;
            cont++;
        }
    }

    for (int i = 0; i < cont; i++){
        for (int j = i + 1; j < cont; j++){
            if (array_total[i] > array_total[j]){
                swapInt(&array_total[i], &array_total[j]);
                swap(&array_nome[i], &array_nome[j]);
            }
        }
    }

    for (int i = 0; i < cont; i++){
        printf("%s\n", array_nome[i]);
    }
    
    for (int i = 0; i < cont; i++){
    free(array_nome[i]);
    }
    free(array_total);  
    free(array_nome);
    
    return 0;
}

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}
void swapInt(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int converter(int h, int m){
    int total=0;
    if(h == 0){
        total = 1440 + m;
        return total;
    }
    else{
        total = (h * 60) + m;
        return total;
    }
    return 1;
}
int conferir(int total, int p){
    int meia_noite = 1440;
    if((total <= (meia_noite + p)) && (total >= (meia_noite - p))){
        return 1;
    }
    return 0;
}