#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node *next;
}Node;

void add(Node **head, int num){
    Node *new =(Node **) malloc(sizeof(Node*));
    if(new == NULL) return;

    new->num = num;
    new->next = NULL;

    if(*head == NULL){
        *head = new;
        return;
    }

    Node *cur = *head;

    while(cur->next != NULL){
        cur = cur->next;
    }

    cur->next = new;
}

void pop(Node **head){
    if(*head == NULL) return;

    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }

    Node *cur = *head;
    Node *anterior = NULL;

    while(cur->next != NULL){
        if(cur == *head){
            anterior = *head;
            cur = cur->next;
            continue;
        }
        cur = cur->next;
        anterior = anterior->next;
    }
    anterior->next = NULL;
    free(cur);
}




int getNum(Node *head, int num){
    if(head == NULL) return -1;

    while(head != NULL){
        if(head->num == num){
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main(){
    Node *head = NULL;
    return 0;
}