#ifndef type_h
#define type_h

/* 数组元素 */
typedef struct {
    int value;
} element;

/* 线性节点 */
typedef struct linear_node {
    int value;
    struct linear_node *next;
} LNode;

/* 二叉树节点 */
typedef struct binary_node {
    int value;
    struct binary_node *left;
    struct binary_node *right;
} BNode;

void BNode_init(BNode *node, int value) {
    node->left = NULL;
    node->right = NULL;
    node->value = value;
}


#endif
