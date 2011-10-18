#include <stdio.h>
#include <string.h>

void set_string(char str[]) {
    printf("now in function:\n");
    /* 形参是指针,指向实参 */
    printf("size of str is %d\n", sizeof(str));
    printf("strlen str is %d\n", strlen(str));
}

int main()
{
    /******************* sizeof 和 strlen , 应用到指针上, 形参上 *****************/

    char str[] = "123456789abcdef";
    printf("init: char str[] = %s\n", str);
    /* 数组首地址, sizeof统计实际占用的字节数,包括'\0\' */
    printf("size of str is %d\n", sizeof(str));
    printf("strlen str is %d\n", strlen(str));

    char *p = str;
    printf("init: char *p = str \n");

    /* 指针类型, sizeof值依电脑位数而定,32位机是4字节,64位机是8字节*/
    printf("size of p is %d\n", sizeof(p));
    printf("strlen p is %d\n", strlen(p));

    set_string(str);

    /******************** 内存拷贝 ***************************************/
    char *q = malloc(sizeof(str));
    printf("%s\n", q);
    memset(q, 0, sizeof(str));
    printf("%s\n", q);
    memcpy(q, p, sizeof(str));
    printf("%s\n", q);

    memset(q, 0, strlen(str)+1);
    printf("%s\n", q);
    strncpy(q, p, strlen(str)+1);
    printf("%s\n", q);
    return 0;
}
