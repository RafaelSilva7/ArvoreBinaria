//
// Created by Rafael da Costa Silva, on 16/02/18.
// E-mail: rafaelcs@uft.edu.br
//

#include "stack.h"

void stack_ini(stack *stack1) {
    if(stack1 != NULL){
        stack1->top = -1;
        stack1->data = (node**) malloc(sizeof(node*)); // Aloco somente o espaco para um elemento
    }

}

void stack_push(stack *stack1, node *node1) {
    if(stack1 != NULL){
        stack1->top++;
        stack1->data = realloc(stack1->data, sizeof(node*) * (stack1->top + 1));
        stack1->data[stack1->top] = node1;
    }
}

node * stack_pop(stack *stack1) {
    if(stack1 != NULL || stack1->top >= 0){
        node *aux = stack1->data[stack1->top];
        stack1->data = realloc(stack1->data, sizeof(node*) * (stack1->top--));
        return aux;
    }

    return NULL;
}

int stack_empty(stack *stack1) {
    if(stack1 == NULL || stack1->top < 0)
        return 1;
    return 0;
}

void stack_free(stack *stack1) {
    if(stack1 != NULL){
        free(stack1->data);
        stack1 = NULL;
    }
}

node * stack_top(stack *stack1) {
    if(stack1 == NULL || stack1->top < 0){
        return 0;
    }
    return stack1->data[stack1->top];
}
