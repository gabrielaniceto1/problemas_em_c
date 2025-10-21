/* --- Tipos e estruturas --- */
typedef int Key;
typedef int Value;

typedef enum {
    EMPTY = 0,    /* nunca usado */
    TOMBSTONE = 1,/* removido (túmulo) */
    USED = 2      /* ocupado */
} SlotState;

typedef struct {
    SlotState state;
    Key  key;
    Value value;
} Slot;

/* --- Parâmetros da tabela --- */
#define M 101
int m = M;            /* tamanho lógico */
Slot table[M];        /* global -> inicia zerado (state=0=EMPTY) */

/* --- Utilitários --- */
int h(Key k) { return (k >= 0) ? k : -k; }
int eq(Key a, Key b) { return a == b; }

/* --- BUSCA (linear probing; NÃO para em TOMBSTONE) --- */
int search(Key k) {
    int i = h(k) % m, start = i;
    while (table[i].state != EMPTY) {          /* EMPTY = nunca usado */
        if (table[i].state == USED && eq(table[i].key, k)) return i;
        i = (i + 1) % m;
        if (i == start) break;                 /* dei a volta */
    }
    return -1;                                  /* não achou */
}

/* --- REMOÇÃO (marca TOMBSTONE; não vira EMPTY) --- */
int remove(Key k) {
    int pos = search(k);
    if (pos == -1) return 0;
    table[pos].state = TOMBSTONE;
    return 1;
}

/* --- INSERÇÃO (reaproveita primeiro TOMBSTONE) --- */
int insert(Key k, Value v) {
    int i = h(k) % m, start = i;
    int tomb = -1;

    while (table[i].state != EMPTY) {
        if (table[i].state == USED && eq(table[i].key, k)) {
            table[i].value = v;                /* atualiza se já existir */
            return 1;
        }
        if (table[i].state == TOMBSTONE && tomb == -1) tomb = i;
        i = (i + 1) % m;
        if (i == start) break;
    }

    {
        int alvo = (tomb != -1) ? tomb : i;
        if (table[alvo].state == USED) return 0; /* tabela cheia */
        table[alvo].state = USED;
        table[alvo].key   = k;
        table[alvo].value = v;
        return 1;
    }
}

/* --- (opcional) Reset explícito --- */
void ht_clear(void) {
    int i;
    for (i = 0; i < m; ++i) table[i].state = EMPTY;
}
