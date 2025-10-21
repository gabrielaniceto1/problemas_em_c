#include <stdlib.h>

typedef struct Tree{
    int val;
    Tree *right;
    Tree *left;
}Tree;

void inserir(Tree **head, int val){
    if(*head == NULL){
        Tree *novo = (Tree *)malloc(sizeof(Tree));
        if(novo == NULL) return;

        novo->val = val;
        novo->left = NULL;
        novo->right = NULL; 
        *head = novo;
        return;
    }
    if((*head)->val > val){
        inserir(&(*head)->left,val);
    }
    else{
        inserir(&(*head)->right,val);
    }
}