#ifndef tree_h
#define tree_h

#include <stdio.h>
#include "stack.h"
#include "type.h"
#include "queue.h"

/* 完全二叉树 链式实现 */
void *tree_create(int size, void *node_init_p(int), void *insert_p(void, int)) {
    void *root = node_init_p(rand() % MAX);
    void *node = root;

    queue *q = queue_init(size);
    queue_add(q, (void *)root);
    process((BNode *)root);
    int i=0;
    int flag = (size-1)/2;
    for(i; i<flag; i++) {
        node = queue_del(q);
        insert_p((BNode *)node, rand() % MAX);
        insert_p((BNode *)node, rand() % MAX);
        queue_add(q, ((BNode *)node)->left);
        queue_add(q, ((BNode *)node)->right);

        process(((BNode *)node)->left);
        process(((BNode *)node)->right);
    }
    if(size % 2 == 0) {
        node = queue_del(q);
        insert_p((BNode *)node, rand() % MAX);
        process(((BNode *)node)->left);
    }
    printf("\n");
    return root;
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
    queue *q = queue_init(100);
    while(node) {
        process(node);
        if(node->left) {
            queue_add(q, node->left);
        }
        if(node->right) {
            queue_add(q, node->right);
        }
        node = queue_del(q);
    }
}

void order_test() {
    /* 构造一颗完全二叉树 */
    printf("create a tree:\n");
    BNode *root = (BNode *)tree_create(8, (void *)BNode_init, insert_bnode);

    /* 层序 */
    printf("level order retrieve:\n");
    traverse(root);
    printf("\n");

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
    //iter_order(root, order_type);

}

/* 大根堆 数组实现 */
/* 调整当前节点 */
void max_heapify(element *A, int i, int n) {
    /* 根从1开始，左孩子为2i，右孩子为2i+1 */
    int left = 2 * i;
    int right = left + 1;
    /* 父，左，右，三节点必有最大 */
    int largest;
    largest = left < n ? (A[left].value > A[i].value ? left : i) : i;
    largest = right < n ? (A[right].value > A[largest].value ? right : largest) : largest;
    /* 父不最大，最大易父 */
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

void heap_test() {
    int size=10;
    element *a = (element *) malloc( sizeof(element) * size);
    array_set_random(a, size);
    print_array(a, size);
    build_max_heap(a, size);
    print_array(a, size);
}

/* 线索二叉树 */

/* 排序二叉树 */

void test_tree() {
    order_test();
    //heap_test();

}
#endif
