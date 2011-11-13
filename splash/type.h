#ifndef type_h
#define type_h

#define MAX 100

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

/* 数组随机初始化 */
void array_set_random(element array[], int n) {
    srand(time(NULL));
    int i=0;
    for(; i<n; i++) {
        array[i].value = rand() % MAX;
    }
}

/* 打印数组 */
void print_array(element array[], int n) {
    int i=0;
    for(; i<n; i++) {
        printf("%02d ", array[i].value);
    }
    printf("\n");
}

/* 遍历类型:前序，中序，后序，层序 */
typedef enum {
    PREORDER,
    INORDER,
    POSTORDER,
    LEVELORDER
} order_t;

typedef enum {
    BUBBLE_SORT,
    INSERTION_SORT,
    SELECTION_SORT,
    GNOME_SORT,
    SHELL_SORT,
    MERGE_SORT,
    QUICK_SORT,
    HEAP_SORT,
} sort_t;

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

#endif
