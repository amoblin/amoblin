#ifndef stack_h
#define stack_h

#include <stdlib.h>
#include "type.h"

/* 链栈 */
LNode *stack_init() {
    LNode* stack =(LNode *) malloc( sizeof( LNode ) );
    if( stack == NULL ) {
        printf("Error!");
        exit(0);
    }
    stack->next == NULL;
    return stack;
}

LNode *stack_pop(LNode *stack) {
    LNode *target = stack->next;
    if( target == NULL) {
        printf("stack is empty.\n");
        exit(0);
    }
    stack->next = target->next;
    return target;
}

void stack_clear( LNode *stack ) {
    if( stack == NULL ) {
    } else {
        while( stack->next != NULL ) {
            stack_pop( stack );
        }
    }
}

void stack_push(LNode *stack , LNode *node) {
    node->next = stack->next;
    stack->next = node;
}

void test_stack() {
    LNode *stack = stack_init();
    stack_push(stack, LNode_init(0, NULL));
    stack_push(stack, LNode_init(2, NULL));
    stack_push(stack, LNode_init(3, NULL));
    stack_push(stack, LNode_init(7, NULL));
    stack_push(stack, LNode_init(8, NULL));
    stack_push(stack, LNode_init(9, NULL));
    printf("%d\t", stack_pop(stack)->value);
    printf("%d\t", stack_pop(stack)->value);
    printf("%d\t", stack_pop(stack)->value);
    printf("%d\t", stack_pop(stack)->value);
    printf("%d\t", stack_pop(stack)->value);
    printf("\n");
}

#endif
