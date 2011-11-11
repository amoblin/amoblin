#ifndef tree_h
#define tree_h

#include <stdio.h>
#include "stack.h"
#include "type.h"
#include "queue.h"

void append_left(BNode *node, int value) {
    BNode *left;
    node_init(left);
    node->left = left;
}

void append_right(BNode *node, int value) {
    BNode *right;
    node_init(right);
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
    LNode *stack[1024];
    for(;;) {
        /* 在node为NULL时返回上一层 */
        for(; node; node = node->left) {
            push(stack, node);
        }
        node = pop(stack);
        /* 在node为空时遍历完成 */
        if( !node ) {
            break;
        }
        printf("%d", node->data);
        node = node->right;
    }
}

/* 层序遍历 */
void traverse(BNode *node) {
    queue_init();

}

/* 小根堆 */

/* 调整当前节点 */
void max_heapify(element *A, int i, int n) {
    int left = 2 * i;
    int right = left + 1;
    int largest;
    largest = left < n ? (A[left] > A[i] ? left : i) : i;
    largest = right < n ? (A[right] > A[small] ? right : small) : small;
    if(largest != i) {
        swap(A[small].value, A[i].value);
        max_heapify(A, small, n);
    }
}
void build_max_heap(element *heap, int n) {
    int i = n / 2;
    for(; i>=0; i--) {
        max_heapify(heap, i, n);
    }
}

void test_tree() {
    BNode *root;
    node_init(root);
    int i;
    for(i=0; i<4; i++) {
        append_left(root, rand()%100);
        append_right(root, rand()%100);
    }
}

#endif
