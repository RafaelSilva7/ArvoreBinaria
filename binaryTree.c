//
// Created by Rafael da Costa Silva, on 16/02/18.
// E-mail: rafaelcs@uft.edu.br
//

#include "binaryTree.h"
#include "stack.h"

void insertion(node ** root, int x){
    node * novo = (node*) malloc(sizeof(node));
    novo->info = x;
    novo->left = novo->right = NULL;

    if(*root == NULL)
        *root = novo;
    else {
        node * aux = *root;
        while((aux->left != NULL && x < aux->info) || (aux->right != NULL && x >= aux->info)){
            if(x < aux->info)
                aux = aux->left;
            else
                aux = aux->right;
        }
        if (x < aux->info) {
            aux->left = novo;
        } else {
            aux->right = novo;
        }
    }
}

void insertion_r(node ** root, int x){
    // Verifica se a raiz atual é o local aonde deve ser inserido o novo valor
    if(*root == NULL){
        node * novo = (node*) malloc(sizeof(node));
        novo->info = x;
        novo->left = novo->right = NULL;
        *root = novo;
        // Percorre a arvore a procura do local a ser inserido o novo elemento
    } else{
        if(x < (*root)->info)
            insertion_r(&((*root)->left), x);
        else
            insertion_r(&((*root)->right), x);
    }
}

void pre_Order(node * root){
    if(root != NULL){
        printf("%d ",root->info);
        pre_Order(root->left);
        pre_Order(root->right);
    }
}

void in_Order(node * root){
    if(root != NULL){
        pos_Order(root->left);
        printf("%d ",root->info);
        pos_Order(root->right);
    }
}

void pos_Order(node * root){
    if(root != NULL){
        pos_Order(root->left);
        pos_Order(root->right);
        printf("%d ",root->info);
    }
}

int find(node * root, int x){
    if(root == NULL) return 0;
    if(x < root->info){
        return find(root->left, x);
    } else if(x > root->info){
        return find(root->right, x);
    }
    return 1;
}


int great(int x, int y){
    return ((x > y) ? x : y);
}

int height(node * root){
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    else {
        return 1 + great(height(root->left), height(root->right));
    }
}

void pre_OrderIt(node * root){
    if(root != NULL){
        node * temp;
        stack stack1;
        stack_ini(&stack1);
        stack_push(&stack1, root);

        while(!stack_empty(&stack1)){
            temp = stack_pop(&stack1);
            printf("%d ", temp->info);
            if(temp->right != NULL)
                stack_push(&stack1, temp->right);
            if(temp->left != NULL)
                stack_push(&stack1, temp->left);
        }
        printf("\n");
    }
}

void pos_OrderIt(node *root) {
    if(root != NULL){
        node * temp, * aux = NULL;
        stack stack1;
        stack_ini(&stack1);
        stack_push(&stack1, root);

        while(!stack_empty(&stack1)){
            temp = stack_top(&stack1);
            if((temp->left == NULL && temp->right == NULL) || temp->right == aux){
                temp = stack_pop(&stack1);
                printf("%d ", temp->info);
                aux = temp;
                continue;
            }
            if(temp->right != NULL) {
                stack_push(&stack1, temp->right);
            }
            if(temp->left != NULL) {
                stack_push(&stack1, temp->left);
            }
        }
        printf("\n");
    }
}

void in_OrderIt(node *root) {
    node * temp = root;
    stack stack1;
    stack_ini(&stack1);

    while(!stack_empty(&stack1) || temp != NULL){
        if(temp != NULL){               // Caso o node atual não seja nulo
            stack_push(&stack1, temp);  // adicono ele a pilha
            temp = temp->left;          // e me locomovo para a esquerda
        } else {                        // Caso ele seja nulo
            temp = stack_pop(&stack1);  // removo o topo da pilha
            printf("%d ", temp->info);  // apresento seu valor
            temp = temp->right;         // me locomovo para a esquerda
        }
    }
    printf("\n");
}

int height_node(node *root, int value) {
    if(root != NULL){
        if(value < root->info && root->left != NULL){
            return 1 + height_node(root->left, value);
        } else if(value > root->info && root->right != NULL){
            return 1 + height_node(root->right, value);
        }
        return 1;
    }
    return 0;
}

int isFull(node *root, int h, int h_node) {
    if(root != NULL){
        if(root->left == NULL && root->right == NULL){
            return (h == h_node) ? 1 : 0;
        }
        if(root->left != NULL && root->right != NULL){
            if( isFull(root->left, h, h_node+1) && isFull(root->right, h, h_node+1))
                return 1;
        }
    }
    return 0;
}

void insertion_reflex(node **root, int x) {
    // Verifica se a raiz atual é o local aonde deve ser inserido o novo valor
    if(*root == NULL){
        node * novo = (node*) malloc(sizeof(node));
        novo->info = x;
        novo->left = novo->right = NULL;
        *root = novo;
        // Percorre a arvore a procura do local a ser inserido o novo elemento
    } else{
        if(x > (*root)->info)
            insertion_r(&((*root)->left), x);
        else
            insertion_r(&((*root)->right), x);
    }
}

node *reflex_tree(node *root) {
    if(root == NULL) return NULL;
    node * newTree = NULL;

    node * temp;
    stack stack1;
    stack_ini(&stack1);
    stack_push(&stack1, root);

    while(!stack_empty(&stack1)){
        temp = stack_pop(&stack1);
        insertion_reflex(&newTree, temp->info);
        if(temp->right != NULL)
            stack_push(&stack1, temp->right);
        if(temp->left != NULL)
            stack_push(&stack1, temp->left);
    }
    return newTree;
}

void remove_it(node **root, int x) {
    if(*root != NULL){
        node * aux = *root;
//        Encontra o elemento a ser removido
        while(aux != NULL){
            if(x == aux->info)
                break;
            else if(x < aux->info)
                aux = aux->left;
            else
                aux = aux->right;
        }
//        Verifica se o elemento foi encontrado
        if(aux != NULL){
            node * tmp = aux;
//            1- O elemento possui 0 filhos
            if(aux->left == NULL && aux->right == NULL){
                free(aux);
//            2- O elemento possui 2 filhos
            } else if(aux->left != NULL && aux->right != NULL){
                tmp = small_rem(aux->right);
                tmp->right = aux->right;
                tmp->left = aux->left;
                aux->left = aux->right = NULL;
                free(aux);
                aux = tmp;
//            3- O elemento possui 1 filho
            } else {
                if(aux->right != NULL){
                    tmp = aux->right;
                } else{
                    tmp = aux->left;
                }
                free(aux);
                aux = tmp;
            }
        }
    }
}

node * small_rem(node ** root) {
    if(*root != NULL){

//        Percorre a arvore até o menor elemento
        if((*root)->left != NULL){
            return small_rem(&(*root)->left);
        }

        node * aux = *root;
//        Remove o menor elemento da arvore
        if((*root)->right != NULL){
            *root = (*root)->right;
            aux->right = NULL;
        } else
            *root = NULL;
        return aux;
    }
    return NULL;
}

void remove_r(node **root, int x) {
    if(*root != NULL){
        node * aux = *root;
//        Encontra o elemento a ser removido
        if(x < aux->info)
            remove_r(&aux->left, x);
        else if(x > aux->info)
            remove_r(&aux->right, x);
        else{
            node * tmp = aux;
//            1- O elemento possui 0 filhos
            if(aux->left == NULL && aux->right == NULL){
                free(aux);
//            2- O elemento possui 2 filhos
            } else if(aux->left != NULL && aux->right != NULL){
                tmp = small_rem(aux->right);
                tmp->right = aux->right;
                tmp->left = aux->left;
                aux->left = aux->right = NULL;
                free(aux);
                aux = tmp;
//            3- O elemento possui 1 filho
            } else {
                if(aux->right != NULL){
                    tmp = aux->right;
                } else{
                    tmp = aux->left;
                }
                free(aux);
                aux = tmp;
            }
        }
    }
}
