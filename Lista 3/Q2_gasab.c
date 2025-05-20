/*
beecrowd | 3149
A Noiva do Trevo
Por Gabriel Bianchin de Oliveira, IFSULDEMINAS/UNICAMP BR Brazil

Existe uma famosa história na cidade de Muzambinho de uma noiva que aparece no trevo da entrada da cidade sempre próximo a meia noite.

Muitos moradores da cidade já relataram que viram a noiva, porém não existe um consenso de qual é o horário certo que ela aparece, principalmente porque 
todos dizem que viram "próximo a meia noite".

Toguro, um grande estudioso de eventos sobrenaturais, está tentando organizar os relatos dos moradores e verificar se houveram relatos verdadeiros.

Como um horário "próximo a meia noite" pode ser tanto alguns minutos antes quanto alguns minutos depois, 
Toguro pediu a sua ajuda para criar um algoritmo que dado o valor M de minutos para ser considerado antes e 
depois da meia noite, o nome do morador e o horário do suposto avistamento, mostrasse de forma ordenada pelo horário os avistamentos que podem ser
catalogados como relatos verdadeiros.

Entrada
A primeira linha da entrada contém um inteiro P representando o valor próximo da meia noite para mais e para menos e um inteiro Q 
representando a quantidade de pessoas que relataram o avistamento.

Nas próximas Q linhas serão lidos duas strings H e N, indicando o horário do relato e o nome do morador, respectivamente.

Limites:

1 <= P <=  59;

1 <= Q <= 1000;

23:01 <= H <= 00:59

1 <= |N| <= 100;

Saída
A saída deverá ser o nome dos moradores que tiveram o relato como verdadeiro ordenados pelo horário que viram.

Obs: avistamentos antes da meia noite ocorreram primeiro que os avistamentos depois da meia noite. 
Em caso de avistamentos no mesmo horário a ordem de registro do avistamento deve ser considerada, ou seja, o avistamento que foi registrado primeiro 
deve aparecer primeiro, assim sucessivamente.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Morador {
    char nome[101];
    int tempo;
    int ordem;
};

int converter(int h, int m);
void trocarMoradores(struct Morador *a, struct Morador *b);

int main() {
    int p, q;
    scanf("%d %d", &p, &q);

    struct Morador moradores[q];
    int cont = 0;

    for (int i = 0; i < q; i++) {
        char horario[6], nome[101];
        scanf("%s %s", horario, nome);

        int h = (horario[0] - '0') * 10 + (horario[1] - '0');
        int m = (horario[3] - '0') * 10 + (horario[4] - '0');

        int total = converter(h, m);

        if (total >= (1440 - p) && total <= (1440 + p)) {
            strcpy(moradores[cont].nome, nome);
            moradores[cont].tempo = total;
            moradores[cont].ordem = cont;
            cont++;
        }
    }

    for (int i = 0; i < cont - 1; i++) {
        for (int j = i + 1; j < cont; j++) {
            if (moradores[i].tempo > moradores[j].tempo ||
               (moradores[i].tempo == moradores[j].tempo && moradores[i].ordem > moradores[j].ordem)) {
                trocarMoradores(&moradores[i], &moradores[j]);
            }
        }
    }

    for (int i = 0; i < cont; i++) {
        printf("%s\n", moradores[i].nome);
    }

    return 0;
}

int converter(int h, int m) {
    int total = h * 60 + m;
    if (h == 0) total += 1440;
    return total;
}

void trocarMoradores(struct Morador *a, struct Morador *b) {
    struct Morador temp = *a;
    *a = *b;
    *b = temp;
}
