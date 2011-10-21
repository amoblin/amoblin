#include <stdlib.h>
#include "type.h"

LNode *create_stack() {
    LNode* stack =(LNode *) malloc( sizeof( LNode ) );
    if( stack == NULL ) {
        printf("Error!");
        exit(0);
    }
    stack->next == NULL;
    return stack;
}

int stack_pop(LNode *stack) {
    LNode *target = stack->next;
    if( target == NULL) {
        printf("stack is empty.\n");
        exit(0);
    }
    int value = target->value;
    stack->next = target->next;
    free(target);
    return value;
}


void stack_clear( LNode *stack ) {
    if( stack == NULL ) {
    } else {
        while( stack->next != NULL ) {
            stack_pop( stack );
        }
    }
}

void stack_push( int value, LNode *stack ) {
    LNode *node = (LNode *) malloc( sizeof( LNode) );
    if( node == NULL ) {
        printf("error!");
        return;
    }

    node->value = value;
    node->next = stack->next;
    stack->next = node;
}

void test_stack() {
    LNode *stack = create_stack();
    stack_push(0, stack);
    stack_push(2, stack);
    stack_push(3, stack);
    stack_push(7, stack);
    stack_push(8, stack);
    stack_push(9, stack);
    printf("%d\t", stack_pop(stack));
    printf("%d\t", stack_pop(stack));
    printf("%d\t", stack_pop(stack));
    printf("%d\t", stack_pop(stack));
    printf("%d\t", stack_pop(stack));
    printf("\n");
}
