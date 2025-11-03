#include <stdlib.h>
#include <stdio.h>

typedef struct Tree{
    int val;
    struct Tree *right;
    struct Tree *left;
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
    if(root == NULL) return -1;
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

int verificar_filhos_par(Tree *root){
    if(root == NULL) return 1;
    if(verificar_filhos_par(root->left) == 0 || verificar_filhos_par(root->right) == 0) return 0;
    if((root->left == NULL && root->right == NULL) || (root->left != NULL && root->right != NULL)) return 1;
    return 0;    
}

int main(){

    Tree * root = NULL;
    inserir(&root, 1);
    inserir(&root, 2);
    inserir(&root, 3);
    inserir(&root, 4);
    inserir(&root, 5);
    inserir(&root, 6);
    inserir(&root, 7);
    inserir(&root, 8);

    int valor = verificar_filhos_par(root);
    printf("%d", valor);
    return 0;
}