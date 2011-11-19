#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>
#include "type.h"

typedef struct {
    int size;
    int front;
    int rear;
    BNode **array;
} queue;

queue *queue_init(int max) {
    queue *q = malloc(sizeof(queue));
    /* 预留一个浪费用 */
    q->size = max+1;
    q->front = 0;
    q->rear = 0;
    q->array = (BNode **)malloc(sizeof(BNode *) * (max+1));
    return q;
}

int queue_is_empty(queue *q) {
    return q->front == q->rear;
}

int queue_is_full(queue *q) {
    return (q->rear+1) % q->size == q->front;
}

int queue_add(queue *q, BNode *node) {
    /* 队满判断 */
    if( queue_is_full(q) ) {
        return 1;
    }
    q->array[ q->rear ] = node;
    q->rear = (q->rear+1) % q->size;
    return 0;
}

void queue_set_random(queue *q, int max) {
    srand(time(NULL));
    int i=0;
    BNode *node;
    while( ! queue_is_full(q) ) {
        node = BNode_init(rand() % max);
        printf("%d ", node->value);
        queue_add(q, node);
    }
    printf("\n");
}

BNode *queue_del(queue *q) {
    /* 队空判断 */
    if( queue_is_empty(q) ) {
        return NULL;
    }
    BNode *tmp = q->array[ q->front ];
    q->front = (q->front+1) % q->size;
    return tmp;
}

void test_queue() 
{
    queue *q = queue_init(10);

    queue_set_random(q, 100);

    int i;
    while( ! queue_is_empty(q) ) {
        printf("%d ", queue_del(q)->value);
    }
    printf("\n");
}

#endif
