//
// Created by Rafael da Costa Silva, on 16/02/18.
// E-mail: rafaelcs@uft.edu.br
//

#include "binaryTree.h"

int main() {
    node * tree = NULL;

    insertion_r(&tree, 10);
    insertion_r(&tree, 6);
    insertion_r(&tree, 12);
    insertion(&tree, 11);
    insertion(&tree, 3);
    insertion(&tree, 8);
    insertion(&tree, 13);
//    insertion(&tree, 9);


    pre_Order(tree);
    if(find(tree, 8) == 1){
        printf("\n%s\n", "Numero encontrado." );
    };

    printf("%s %d\n", "Altura:", height(tree) );
    printf("pre_OrderIt:\n");
    pre_OrderIt(tree);
    printf("in_OrderIt:\n");
    in_OrderIt(tree);
    printf("pos_OrderIt:\n");
    pos_OrderIt(tree);
    if(isFull(tree, height(tree)+1, 1))
        printf("isFull: yes\n");
    else
        printf("isFull: not\n");


    return 0;
}