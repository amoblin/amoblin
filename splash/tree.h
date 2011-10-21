#include <stdio.h>
#include "stack.h"
#include "type.h"

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
    tree_pointer stack[1024];
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

