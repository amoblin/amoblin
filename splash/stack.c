#include "stack.h"

int IsEmpty( stack S ) {
    return S->next == NULL;
}

stack CreateStack( void ) {
    stack S;
    S = malloc( sizeof( struct stack_node ) );
    if( S == NULL ) {
        FatalError( "Out of space!!!" );
    }
    S->next == NULL;
    MakeEmpty( S );
    return S;
}

void MakeEmpty( stack S ) {
    if( S == NULL ) {
        Error( "Must use CreateStack first." );
    } else {
        while( !IsEmpty( S ) ) {
            Pop( S );
        }
    }
}

void Push( ElementType X, stack S ) {
    stack_node_ptr TmpCell;
    TmpCell = malloc( sizeof( struct stack_node ) );
    if( TmpCell == NULL ) {
        FatalError( "Out of space!!!" );
    } else {
        TmpCell->element = X;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}

ElementType Top( stack S ) {
    if( !IsEmpty( S ) ) {
        return S->next->element;
    }
    Error( "Empty stack." );
    return 0;
}


