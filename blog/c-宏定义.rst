==============
C中宏定义研究
==============

简单替换

.. sourcecode:: c

    #define PI 3.14

带参数（宏函数）

.. sourcecode:: c

    #define SQUARE(a) ((a)*(a))

注意两点：

1. 参数要加括号

#. 整体要加括号

原因很简单，宏只是简单的替换。需要括号来保证替换后不受运算符优先级的干扰。

带#的宏函数

.. sourcecode:: c

    #define STR(a) #a

替换结果为将参数加引号。而下例：

.. sourcecode:: c

    #define STR(a) "a"

会替换为字符串"a"，和参数无关。

这里有一个原则：遇引号不替换

带##的宏函数

.. sourcecode:: c

    #define PRE(a) L##a

会把参数a前面加上L。

看下面一个例子：

.. sourcecode:: c

    #define PRE(a,b) vo##a##b()
    PRE(id te,st) {
        printf("Hello, world!\n");
    }

展开后为：

.. sourcecode:: c

    void test() {
        printf("Hello, world!\n");
    }

