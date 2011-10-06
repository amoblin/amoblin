#include <stdio.h>
#include "stack.h"

typedef struct tree_node *tree_point;
typedef struct tree_node {
    int data;
    tree_point left_child;
    tree_point right_child; 
};

void process( tree_pointer ptr ) {
    printf("%d", ptr->data);
}

/* 前序遍历 */
void preorder(tree_pointer ptr) {
    if( ptr == NULL ) {
        return;
    }

    process( ptr );
    preorder( ptr->left_child );
    preorder( ptr->right_child );
}

/* 中序遍历 */
void inorder( tree_pointer ptr ) {
    if( ptr == NULL ) {
        return;
    }

    inorder( ptr->left_child );
    process( ptr );
    inorder( ptr->right_child );
}

/* 后序遍历 */
void postorder( tree_pointer ptr ) {
    if( ptr == NULL ) {
        return;
    }

    postorder( ptr->left_child );
    postorder( ptr->right_child );
    process( ptr );
}

/* 用栈模拟递归，迭代实现 */

/* 非递归中序遍历 */
void iter_inorder( tree_pointer node ) {
    tree_pointer stack[1024];
    for(;;) {
        /* 在node为NULL时返回上一层 */
        for(; node; node = node->left_child) {
            push(stack, node);
        }
        node = pop(stack);
        /* 在node为空时遍历完成 */
        if( !node ) {
            break;
        }
        printf("%d", node->data);
        node = node->right_child;
    }
}

/* 层序遍历 */

