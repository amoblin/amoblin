
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
