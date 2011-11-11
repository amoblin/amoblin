#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>
#include "type.h"

typedef struct {
    int capacity;
    int size;
    int front;
    int rear;
    BNode **array;
} queue;

void queue_init(queue *q, int max) {
    q->capacity = max;
    q->size = 0;
    q->front = 0;
    q->rear = 0;
    q->array = (BNode **)malloc(sizeof(BNode *) * max);
}

void queue_add(queue *q, BNode *node) {
    q->array[ q->rear ] = node;
    (q->size)++;
    (q->rear)++;
}

void queue_set_random(queue *q, int max) {
    srand(time(NULL));
    int i=0;
    BNode *node;
    for(; i< q->capacity; i++) {
        node = malloc( sizeof(BNode) );
        node_init(node, rand() % max);
        printf("%d ", node->value);
        queue_add(q, node);
    }
    printf("\n");
}

BNode *queue_del(queue *q) {
    return q->array[ q->front++ ];
}

void test_queue() 
{
    queue *q = malloc(sizeof(queue));

    queue_init(q, 10);

    queue_set_random(q, 100);

    int i;
    for(i=0; i< q->capacity; i++) {
        printf("%d ", queue_del(q)->value);
    }
    printf("\n");
}

#endif
