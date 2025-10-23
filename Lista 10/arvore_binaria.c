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

Tree* maior_valor(Tree *root) {
    if (root == NULL) return NULL;
    if (root->right == NULL) return root;
    return maior_valor(root->right);
}

int altura_arvore(Tree *root){
    if(root == NULL) return 0;
    int hleft = altura_arvore(root->left);
    int hright = altura_arvore(root->right);
    return (hleft > hright ? hleft : hright) + 1;
}

void imprimir_folhas(Tree *root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        printf("%d\n", root->val);
    }
    imprimir_folhas(root->left);
    imprimir_folhas(root->right);
}