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
