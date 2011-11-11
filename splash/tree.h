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
    printf("%d ", node->value);
}

/* 前序 中序 后序 递归遍历 */
void order(BNode *node, order_t type) {
    if( node == NULL ) {
        return;
    }

    /* 前序遍历 */
    if(type == PREORDER) {
        process( node );
    }

    order( node->left, type);

    /* 中序遍历 */
    if(type == INORDER) {
        process( node );
    }

    order( node->right, type);

    /* 后序遍历 */
    if(type == POSTORDER) {
        process( node );
    }
}

/* 用栈模拟递归，迭代实现 */

/******************************************
 * 数组栈 前序 中序
 * 前序：((入根，处理，试左)，试出，试右)
 * 中序：((入根，试左)，试出，处理，试右)
 ******************************************/

void iter_order( BNode *bnode, int type) {
    BNode *stack[10];
    int top=-1;
    for(;;) {
        /* for循环，父节点和左子节点入栈 */
        for(; bnode; bnode=bnode->left) {
            top++;
            stack[top] = bnode;
            /* 前序 */
            if(type == PREORDER) {
                process(bnode);
            }
        }
        /* 左子树处理完毕，处理右子树 */
        if(top<0) {
            break;
        }
        bnode = stack[top];
        top--;
        /* 中序 */
        if(type == INORDER) {
            process(bnode);
        }
        if(type == POSTORDER) {
            bnode = stack[top];
            top++;
            stack[top] = bnode->right;
        } else {
            bnode = bnode->right;
        }
    }
    printf("\n");
}

/* 链栈 中序遍历 */
void iter_order_l( BNode *bnode) {
    LNode *stack = stack_init();
    LNode *lnode;
    for(;;) {
        /* 在bnode为NULL时停止下降 */
        for(; bnode; bnode= bnode->left) {
            stack_push(stack, LNode_init(0, bnode));
        }

        /* 处理节点 */
        lnode = stack_pop(stack);
        /* 在node为空时遍历完成 */
        if( lnode == NULL ) {
            break;
        }
        bnode = lnode->bn;

        printf("%d ", bnode->value);

        /* 处理右子树 */
        bnode = bnode->right;
    }
    printf("\n");
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
    append_left(root, rand()%100);
    append_right(root, rand()%100);

    /* 前序 */
    order(root, PREORDER);
    printf("\n");
    iter_order(root, PREORDER);

    /* 中序 */
    order(root, INORDER);
    printf("\n");
    iter_order(root, INORDER);
}
#endif
