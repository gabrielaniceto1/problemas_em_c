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

    struct Morador *moradores = malloc(q * sizeof(struct Morador));
    struct Morador *validos = NULL;
    int total_validos = 0;

    for (int i = 0; i < q; i++) {
        char horario[6], nome[101];
        scanf("%s %s", horario, nome);

        int h = (horario[0] - '0') * 10 + (horario[1] - '0');
        int m = (horario[3] - '0') * 10 + (horario[4] - '0');
        int tempo = converter(h, m);

        strcpy(moradores[i].nome, nome);
        moradores[i].tempo = tempo;
        moradores[i].ordem = i;

        if (tempo >= (1440 - p) && tempo <= (1440 + p)) {
            validos = realloc(validos, (total_validos + 1) * sizeof(struct Morador));
            validos[total_validos++] = moradores[i];
        }
    }

    for (int i = 0; i < total_validos - 1; i++) {
        for (int j = i + 1; j < total_validos; j++) {
            if (validos[i].tempo > validos[j].tempo ||
               (validos[i].tempo == validos[j].tempo && validos[i].ordem > validos[j].ordem)) {
                trocarMoradores(&validos[i], &validos[j]);
            }
        }
    }

    for (int i = 0; i < total_validos; i++) {
        printf("%s\n", validos[i].nome);
    }

    free(moradores);
    free(validos);

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
