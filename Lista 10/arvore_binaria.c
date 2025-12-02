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
void remover_no(Tree **root, int val){
    if(*root == NULL) return;
    if(val < (*root)->val){
        remover_no(&(*root)->left, val);
    }
    else if(val > (*root)->val){
        remover_no(&(*root)->right, val);
    }
    else{
        if((*root)->right == NULL && (*root)->left == NULL){
            Tree *remover = *root;
            *root = NULL;
            free(remover);
        }
        else if((*root)->right == NULL){
            Tree *remover = *root;
            *root = (*root)->left;
            free(remover);
        }
        else if((*root)->left == NULL){
            Tree *remover = *root;
            *root = (*root)->right;
            free(remover);
        }
        else{
            Tree *antSucessor = *root;
            Tree *sucessor = (*root)->left;
            while(sucessor->right != NULL){
                antSucessor = sucessor;
                sucessor = sucessor->right;
            }
            
            (*root)->val = sucessor->val;

            if (antSucessor->right == sucessor) {
                antSucessor->right = sucessor->left;
            }
            else {
                antSucessor->left = sucessor->left;
            }

            free(sucessor);
        }   
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
void preordem(Tree *root){
    if( root != NULL){
        printf("%d ", root->val);
        preordem(root->left);
        preordem(root->right);
    }
    
}
void inordem(Tree *root){
    if(root != NULL){
        inordem(root->left);
        printf("%d ", root->val);
        inordem(root->right);
    }
}
void posordem(Tree *root){
    if(root != NULL){
        posordem(root->left);
        posordem(root->right);
        printf("%d ", root->val);
    }
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

    preordem(root);
    printf("\n");

    inordem(root);
    printf("\n");

    posordem(root);
    printf("\n");
    
    int valor = verificar_filhos_par(root);
    printf("%d", valor);
    return 0;
}