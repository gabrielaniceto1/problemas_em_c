#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int arrival_minutes;
    int critical_minutes;
    struct node *prev;
    struct node *next;
} node;

typedef struct list {
    node *head;
    node *tail;
    int size;
} list;

void init_list(list *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

node* new_node(int arrival_minutes, int critical_minutes) {
    node *n = (node*)malloc(sizeof(*n));
    if (!n) return NULL;
    n->arrival_minutes = arrival_minutes;
    n->critical_minutes = critical_minutes;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

int add_end_list(list *list, int arrival_minutes, int critical_minutes) {
    node *n = new_node(arrival_minutes, critical_minutes);
    if (!n) return 0;
    if (!list->tail) {
        list->head = list->tail = n;
    } else {
        n->prev = list->tail;
        list->tail->next = n;
        list->tail = n;
    }
    list->size++;
    return 1;
}

void clear_list(list *list) {
    node *cur = list->head;
    while (cur) {
        node *nx = cur->next;
        free(cur);
        cur = nx;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int convert_hour_minute_to_minutes(int hour_value, int minute_value) {
    return hour_value * 60 + minute_value;
}

int count_critical_patients(list *list) {
    int number_of_critical_patients = 0;
    int current_slot_start_minutes = 7 * 60;
    node *p = list->head;
    while (p) {
        while (current_slot_start_minutes < p->arrival_minutes) {
            current_slot_start_minutes += 30;
        }
        int waiting_time_minutes = current_slot_start_minutes - p->arrival_minutes;
        if (waiting_time_minutes > p->critical_minutes) {
            ++number_of_critical_patients;
        }
        current_slot_start_minutes += 30;
        p = p->next;
    }
    return number_of_critical_patients;
}

int main(void) {
    int number_of_patients;
    while (scanf("%d", &number_of_patients) == 1) {
        list *list = malloc(sizeof(*list));
        if (!list) return 0;
        init_list(list);

        for (int i = 0; i < number_of_patients; ++i) {
            int hour_value, minute_value, critical_minutes;
            scanf("%d %d %d", &hour_value, &minute_value, &critical_minutes);
            int arrival_minutes = convert_hour_minute_to_minutes(hour_value, minute_value);
            add_end_list(list, arrival_minutes, critical_minutes);
        }

        int answer_critical_patients = count_critical_patients(list);
        printf("%d\n", answer_critical_patients);

        clear_list(list);
        free(list);
    }
    return 0;
}