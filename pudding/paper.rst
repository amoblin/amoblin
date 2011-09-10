毕业论文
---------

代码

.. sourcecode:: python
    :linenos:

    My code goes here.

.. sourcecode:: c
    :linenos:

    double alpha = LEARN_RATE;  //学习率
    double delta_hidden[HIDDEN_NODES], delta_out[OUT_NODES];    //修改量矩阵
    26     Matrix* a1;
    27     matrix_init(in->m, v->n, &a1, DOUBLE);
    28 
    29     Matrix* f1;
    30     matrix_init(a1->m, a1->n, &f1, DOUBLE);
    31 
    32     Matrix* a2;
    33     matrix_init(f1->m, w->n, &a2, DOUBLE);
    34 
    35     Matrix* f2;
    36     matrix_init(a2->m, a2->n, &f2, DOUBLE);
