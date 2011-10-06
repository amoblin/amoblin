typedef struct stack_node *stack_node_ptr;

typedef struct stack_node {
    ElementType element;
    stack_node_ptr next;
};

typedef stack_node_ptr stack;

int IsEmpty( stack S );
stack CreateStack( void );
void DisposeStack( stack S );
void MakeEmpty( stack S );
void Push( ElementType X, stack S );
ElementType Top( stack S );
void Pop( stack S );

