//
// Created by Rafael da Costa Silva, on 16/02/18.
// E-mail: rafaelcs@uft.edu.br
//

#ifndef UNTITLED_BINARYTREE_H
#define UNTITLED_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura basica de uma arvore binaria (seu nó)
typedef struct binaryTree{
    int info;
    struct binaryTree * left;
    struct binaryTree * right;
} node;

/*
*  Insere um novo elemento a arvore binaria de forma iterativa [caso a funca retorne a raiz
* evita o uso de ponteiro de ponteiro]
* node **, raiz da arvore no qual o valor sera inserido
* int, valor que deverá ser inserido na arvore
*/
void insertion(node ** root, int x);

/*
* Insere um novo elemento a arvore binaria de forma recursiva e reflexiva
* node **, raiz da arvore no qual o valor sera inserido
* int, valor que deverá ser inserido na arvore
*/
void insertion_reflex(node ** root, int x);

/*
* Insere um novo elemento a arvore binaria de forma recursiva [caso a funca retorne a raiz
* evita o uso de ponteiro de ponteiro]
* node **, raiz da arvore no qual o valor sera inserido
* int, valor que deverá ser inserido na arvore
*/
void insertion_r(node ** root, int x);

/*
* Realiza a impressão da arvore na forma pre_Order
* node *, arvore a ser impressa
*/
void pre_Order(node * root);

/*
* Realiza a impressão da arvore na forma pos_Order
* node *, arvore a ser impressa
*/
void pos_Order(node * root);

/*
* Realiza a impressão da arvore na forma in_Order
* node *, arvore a ser impressa
*/
void in_Order(node * root);

/*
* Realiza uma busca na arvore a procura de um elemento x
* node *, arvore na a busca será realizada
* int, numero que será buscado
*/
int find(node * root, int x);

/*
* Retorna o maior valor entre dois numeros
* int, Um dos inteiros a ser ananlisado
* int, Segundo inteiro a ser ananlisado
*/
int great(int x, int y);

/*
* Retorna a altura da arvore informada
* node *, raiz da arvore a ser analisada
*/
int height(node * root);

/*
 * Verifica a altura em que o node1 se encontra
 * node *, raiz da arvore em que se encontra o node1
 * node *, node1 a ser analisado
 */
int height_node(node *root, int value);

/*
* Realiza a impressao da arvore em pre_Order de forma iterativa
* node *, arvore a ser impressa
*/
void pre_OrderIt(node * root);

/*
* Realiza a impressão da arvore na forma in_Order de forma iterativa
* node *, arvore a ser impressa
*/
void in_OrderIt(node * root);

/*
* Realiza a impressão da arvore na forma pos_Order de forma iterativa
* node *, arvore a ser impressa
*/
void pos_OrderIt(node * root);

/*
 * Verifica se a arvore informada está cheia [retorna 1] ou não [retorna 0]
 * node *, raiz da arvore a ser vericada
 * int, e a altura da arvore
*/
int isFull(node * root, int h, int h_node);

/*
 * Retorna o node de uma arvore espelho
 * node *, raiz da arvore a ser espelhada
 */
node * reflex_tree(node * root);

/*
 * Remove um elemento da arvore de forma recursiva
 * node **, raiz da arvore a ter o elemento removido
 * int, valor do elemento a ser removido
 */
void remove_r(node ** root, int x);

/*
 * Remove um elemento da arvore de forma iterativa
 * node **, raiz da arvore a ter o elemento removido
 * int, valor do elemento a ser removido
 */
void remove_it(node ** root, int x);

/*
 * Auxiliar de remoção, a função remove e retorna o menor elemento da arvore
 * node **, raiz da arvore a ter o menor elemento removido
 */
node *small_rem(node ** root);

#endif //UNTITLED_BINARYTREE_H
