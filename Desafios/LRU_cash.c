#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int key;
    int value;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct LRUCache{
    int capacity;
    int size;
    Node **map;
    Node *head;
    Node *tail;
} LRUCache;

void removeNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}
void insertFront(LRUCache *obj, Node *node){
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next->prev = node;
    obj->head->next = node;
}
void moveToFront(LRUCache *obj, Node *node){
    removeNode(node);
    insertFront(obj,node);
}
LRUCache* lRUCacheCreate(int capacity) {
    if(capacity <= 0) return NULL;
    LRUCache *obj = (LRUCache *)malloc(sizeof(LRUCache));
    if(!obj) return NULL;
    obj->capacity = capacity;
    obj->size = 0;
    obj->map = (Node**)calloc(10001,sizeof(Node*));

    obj->head = (Node*)malloc(sizeof(Node));
    obj->tail = (Node*)malloc(sizeof(Node));

    obj->head->prev = NULL;
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    obj->tail->next = NULL;

    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node *node = obj->map[key];
    if (node == NULL) return -1;
    moveToFront(obj,node);
    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node * node = obj->map[key];
    if(node != NULL){
        node->value = value;
        moveToFront(obj,node);
        return;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) return;

    newNode->key = key;
    newNode->value = value;

    obj->map[key] = newNode;
    insertFront(obj, newNode);
    obj->size++;

    if(obj->size > obj->capacity){
        Node *remove = obj->tail->prev;
        removeNode(remove);
        obj->map[remove->key] = NULL;
        free(remove);
        obj->size--;
    }
}

void lRUCacheFree(LRUCache* obj) {
    Node* curr = obj->head;
    while (curr != NULL) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }

    free(obj->map);
    free(obj);
}

int main() {
    LRUCache* cache = lRUCacheCreate(2);

    lRUCachePut(cache, 1, 1);
    lRUCachePut(cache, 2, 2);
    printf("get(1) = %d\n", lRUCacheGet(cache, 1)); // 1

    lRUCachePut(cache, 3, 3); // remove chave 2
    printf("get(2) = %d\n", lRUCacheGet(cache, 2)); // -1

    lRUCachePut(cache, 4, 4); // remove chave 1
    printf("get(1) = %d\n", lRUCacheGet(cache, 1)); // -1
    printf("get(3) = %d\n", lRUCacheGet(cache, 3)); // 3
    printf("get(4) = %d\n", lRUCacheGet(cache, 4)); // 4

    lRUCacheFree(cache);
    return 0;
}