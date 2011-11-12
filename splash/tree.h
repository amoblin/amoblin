#ifndef tree_h
#define tree_h

#include <stdio.h>
#include "stack.h"
#include "type.h"
#include "queue.h"

BNode *tree_create(int size) {
    BNode *root = BNode_init( rand() % MAX );

    queue *q = queue_init( (2 << size) - 1 );
    BNode *node = root;
    printf("%d ", node->value);
    int i=0;
    int half =( 2 << (size-2)) - 1;
    for(i; i<half; i++) {
        node->left = BNode_init( rand() % MAX );
        node->right = BNode_init( rand() % MAX );
        printf("%d %d ", node->left->value, node->right->value);

        queue_add(q, node->left);
        queue_add(q, node->right);

        node = queue_del(q);
    }
    printf("\n");
    return root;
}

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

void iter_order( BNode *bnode, order_t type) {
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

        bnode = bnode->right;
    }
    printf("\n");
}

/* 链栈 前序 中序遍历 */
void iter_order_l( BNode *bnode, order_t type) {
    LNode *stack = stack_init();
    LNode *lnode;
    for(;;) {
        /* 在bnode为NULL时停止下降 */
        for(; bnode; bnode= bnode->left) {
            if(type == PREORDER) {
                process(bnode);
            }
            stack_push(stack, LNode_init(0, bnode));
        }

        /* 处理节点 */
        lnode = stack_pop(stack);
        /* 在node为空时遍历完成 */
        if( lnode == NULL ) {
            break;
        }
        bnode = lnode->bn;

        /* 中序 */
        if(type == INORDER) {
            process(bnode);
        }

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

    /* 构造一颗完全二叉树 */
    BNode *root = tree_create(4);

    /* 前序 */
    printf("preorder retrieve:\n");
    order_t order_type = PREORDER;
    order(root, order_type);
    printf("\n");
    iter_order(root, order_type);

    /* 中序 */
    printf("inorder retrieve:\n");
    order_type = INORDER;
    order(root, order_type);
    printf("\n");
    iter_order(root, order_type);

    /* 后序 */
    printf("postorder retrieve:\n");
    order_type = POSTORDER;
    order(root, order_type);
    printf("\n");
    iter_order(root, order_type);
}
#endif
