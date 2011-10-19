#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void set_string(char str[]) {
    printf("now in function:\n");
    /* 形参是指针,指向实参 */
    printf("size of str is %d\n", sizeof(str));
    printf("strlen str is %d\n", strlen(str));
}

void sizeof_and_strlen() {
    /* 随机串 */
    char blank[10];
    printf("%s\n", blank);

    /* 溢出串 */
    char a[3] = "abc";
    printf("%s\n", a);
    printf("%d\n", sizeof(a));
    printf("%d\n", strlen(a));

    /* 零串 */
    char zero[10] = {0};
    int i=0;
    for(; i<10; i++) {
        printf("%d", zero[i]);
    }
    printf("\n");

    char str[] = "123456789abcdef";
    /* 数组首地址, sizeof统计实际占用的字节数,包括'\0' */
    printf("size of str is %d\n", sizeof(str));
    printf("strlen str is %d\n", strlen(str));

    char *p = str;
    printf("init: char *p = str \n");

    /* 指针类型, sizeof值依电脑位数而定,32位机是4字节,64位机是8字节*/
    printf("size of p is %d\n", sizeof(p));
    printf("strlen p is %d\n", strlen(p));

    set_string(str);
}

void memory_copy() {
    char *str =(char*) malloc(3);
    char *tmp = "ab";
    printf("%s\n", str);
    memset(str, 0, strlen(str));
    printf("%s\n", str);
    memcpy(str, tmp, strlen(str));
    printf("%s\n", str);

    memset(str, 0, strlen(str)+1);
    printf("%s\n", str);
    strncpy(str, tmp, strlen(str)+1);
    printf("%s\n", str);

    int test[2];
    memset(test, 0, sizeof(test) * sizeof(int));
    printf("%d\n", test[0]);
}

int main()
{
    /******************* sizeof 和 strlen , 应用到指针上, 形参上 *****************/
    sizeof_and_strlen();

    /******************** 内存拷贝 ***************************************/
    memory_copy();

    /* 运算符优先级 */
    return 0;
}
