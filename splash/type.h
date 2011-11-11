#ifndef type_h
#define type_h

/* 数组元素 */
typedef struct {
    int value;
} element;

/* 二叉树节点 */
typedef struct binary_node {
    int value;
    struct binary_node *left;
    struct binary_node *right;
} BNode;

/* 线性节点 */
typedef struct linear_node {
    /* 测试用 */
    int value;
    /* 二叉树遍历非递归实现 */
    BNode *bn;
    struct linear_node *next;
} LNode;

LNode *LNode_init(int value, BNode *bn) {
    LNode *node = (LNode *) malloc( sizeof( LNode) );
    if( node == NULL ) {
        printf("error!");
        return;
    }

    node->value = value;
    node->bn = bn;
    node->next = NULL;
    return node;
}

BNode *BNode_init(int value) {
    BNode *node = (BNode *) malloc( sizeof( BNode) );
    if( node == NULL ) {
        printf("error!");
        return;
    }

    node->left = NULL;
    node->right = NULL;
    node->value = value;
    return node;
}

typedef enum {
    PREORDER,
    INORDER,
    POSTORDER
} order_t;

#endif
