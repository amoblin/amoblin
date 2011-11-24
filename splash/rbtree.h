#ifndef _RED_BLACK_TREE_H

#define BLACK 1
#define RED 0
#define NIL 0

typedef struct RBNode {
    int color;
    struct RBNode *parent;
    struct RBNode *left;
    struct RBNode *right;
    int value;
} RBNode;

RBNode *RBNode_init(int value) {
    RBNode *node = (RBNode *) malloc( sizeof( RBNode) );
    if( node == NULL ) {
        printf("error!");
        return;
    }

    node->left = NULL;
    node->right = NULL;
    node->value = value;
    node->color = BLACK;
    return node;
}

/* */
RBNode *grandparent(RBNode *n) {
    return n->parent->parent;
}

/* */
RBNode *uncle(RBNode *n) {
    if( n->parent == grandparent(n)->left ) {
        return grandparent(n)->right;
    } else {
        return grandparent(n)->left;
    }
}

/* 左旋 */
void rotate_left(RBNode *pivot) {
    RBNode *parent = pivot->parent;
    RBNode *root = parent->parent;

    /* L0 */
    parent->right = pivot->left;
    if( pivot->left != NIL ) {
        pivot->left->parent = parent;
    }

    /* L1 */
    pivot->parent = root;
    if( root->left == parent ) {
        root->left = pivot;
    } else {
        root->right = pivot;
    }

    /* L2 */
    pivot->left = parent;
    parent->parent = pivot;

}

/* 右旋，参数为旋转后父节点 */
void rotate_right(RBNode *pivot) {
    RBNode *parent = pivot->parent;
    RBNode *root = parent->parent;

    /* R0 */
    parent->left = pivot->right;
    if( pivot->right != NIL ) {
        pivot->right->parent = parent;
    }

    /* R1 */
    pivot->parent = root;
    if( parent == root->left) {
        root->left = pivot;
    } else {
        root->right = pivot;
    }

    /* R2 */
    pivot->right = parent;
    parent->parent = pivot;
}

void insert_case5(RBNode *n);

void insert_case(RBNode *n) {
    /* case 1 */
    if( n->parent == NULL ) {
        n->color = BLACK;

    /* case 2 */
    } else if( n->parent->color == BLACK) {
        return;

    /* case 3 */
    } else if( uncle(n) != NULL && uncle(n)->color == RED ) {
        n->parent->color = BLACK;
        uncle(n)->color = BLACK;
        grandparent(n)->color = RED;
        insert_case(grandparent(n));

    /* case 4 */
    } else if( n == n->parent->right && n->parent == grandparent(n)->left) {
        /* 这里和wikipedia不同，那里参数为旋转前父节点 */
        rotate_left(n);
        n = n->left;
        insert_case5(n);
    } else if( n == n->parent->left && n->parent == grandparent(n)->right) {
        rotate_right(n);
        n = n->right;
        insert_case5(n);

    /* case 5 */
    } else {
        insert_case5(n);
    }
}

void insert_case5(RBNode *n) {
    n->parent->color = BLACK;
    grandparent(n)->color = RED;
    if( n == n->parent->left && n->parent == grandparent(n)->left) {
        /* 这里和wikipedia不同，那里参数为旋转前父节点 */
        rotate_right(n->parent);
    } else {
        rotate_left(n->parent);
    }
}

void test_rbtree() {
    RBNode *root = (RBNode *)tree_create(10, (void *) RBNode_init, insert_case);

    /* 层序 */
    printf("level order retrieve:\n");
    traverse((BNode *)root);
    printf("\n");

    /* 前序 */
    printf("preorder retrieve:\n");
    order_t order_type = PREORDER;
    order((BNode *)root, order_type);
    printf("\n");
    iter_order((BNode *)root, order_type);

    /* 中序 */
    printf("inorder retrieve:\n");
    order_type = INORDER;
    order((BNode *)root, order_type);
    printf("\n");
    iter_order((BNode *)root, order_type);

    /* 后序 */
    printf("postorder retrieve:\n");
    order_type = POSTORDER;
    order((BNode *)root, order_type);
    printf("\n");
    //iter_order(root, order_type);
}

#endif
