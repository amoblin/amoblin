#ifndef tree_h
#define tree_h

#include <stdio.h>
#include "stack.h"
#include "type.h"
#include "queue.h"

void append_left(BNode *node, int value) {
    BNode *left = BNode_init(value);
    node->left = left;
}

void append_right(BNode *node, int value) {
    BNode *right = BNode_init(value);
    node->right= right;
}

void process( BNode *node) {
    printf("%d", node->value);
}

/* 前序遍历 */
void preorder(BNode *node) {
    if( node == NULL ) {
        return;
    }

    process( node );
    preorder( node->left);
    preorder( node->right);
}

/* 中序遍历 */
void inorder( BNode *node) {
    if( node == NULL ) {
        return;
    }

    inorder( node->left );
    process( node );
    inorder( node->right );
}

/* 后序遍历 */
void postorder( BNode *node ) {
    if( node == NULL ) {
        return;
    }

    postorder( node->left );
    postorder( node->right );
    process( node );
}

/* 用栈模拟递归，迭代实现 */

/* 非递归中序遍历 */
void iter_inorder( BNode *node ) {
    LNode *stack = stack_init();
    for(;;) {
        /* 在node为NULL时返回上一层 */
        for(; node; node = node->left) {
            stack_push(stack, LNode_init(0, node));
        }
        node = stack_pop(stack)->bn;
        /* 在node为空时遍历完成 */
        if( !node ) {
            break;
        }
        printf("%d", node->value);
        node = node->right;
    }
}

/* 层序遍历 */
void traverse(BNode *node) {
    //queue_init();
}

/* 小根堆 */

/* 调整当前节点 */
void max_heapify(element *A, int i, int n) {
    int left = 2 * i;
    int right = left + 1;
    int largest;
    largest = left < n ? (A[left].value > A[i].value ? left : i) : i;
    largest = right < n ? (A[right].value > A[largest].value ? right : largest) : largest;
    if(largest != i) {
        swap(A[largest].value, A[i].value);
        max_heapify(A, largest, n);
    }
}
void build_max_heap(element *heap, int n) {
    int i = n / 2;
    for(; i>=0; i--) {
        max_heapify(heap, i, n);
    }
}

void test_tree() {
    BNode *root =  BNode_init(rand()%100);
    int i;
    for(i=0; i<4; i++) {
        append_left(root, rand()%100);
        append_right(root, rand()%100);
    }
}

#endif
