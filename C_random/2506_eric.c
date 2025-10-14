#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    struct Node* prev;
    int M, C;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
} LinkedList;

Node* new_Node(Node* next, Node* prev, int M, int C) {
    Node* node = malloc(sizeof(Node));
    node->next = next;
    node->prev = prev;
    node->M = M;
    node->C = C;
    return node;
}

LinkedList* new_LinkedList() { return calloc(1, sizeof(LinkedList)); }

void free_LinkedList(LinkedList* list) {
    Node* cur = list->head;
    Node* temp;
    while (cur != NULL) {
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(list);
}

void enqueue(LinkedList* list, int M, int C) {
    Node* node = new_Node(NULL, list->tail, M, C);
    if (list->tail == NULL)
        list->head = node;
    else
        list->tail->next = node;
    list->tail = node;
}

Node* dequeue(LinkedList* list) {
    if (list->head == NULL) return NULL;
    Node* first = list->head;
    list->head = first->next;
    if (list->head == NULL)
        list->tail = NULL;
    else
        list->head->prev = NULL;
    return first;
}

int peak(LinkedList* list) {
    if (list->head == NULL) return 0x7fffffff;
    return list->head->M;
}

int main() {
    int N, H, M, C;
    while (scanf("%d", &N) != EOF) {
        LinkedList* list = new_LinkedList();
        int died = 0;
        int actualTime = 0;
        int waiting = 0;
        int add = 0;
        for (int i = 0; i < 38; i++) {
            if (add < N) {
                if (!waiting) {
                    scanf("%d %d %d", &H, &M, &C);
                    M += (H - 7) * 60;
                    waiting = 1;
                }
                if (M <= actualTime) {
                    enqueue(list, M, C);
                    waiting = 0;
                    add++;
                }
            }

            if (peak(list) <= actualTime) {
                Node* first = dequeue(list);
                if (first->M + first->C < actualTime) {
                    died++;
                }
                free(first);
            }
            actualTime += 30;
        }
        printf("%d\n", died);

        free_LinkedList(list);
    }
    return 0;
}