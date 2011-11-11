/********************************
 *
 * 2011-10-21 14:59 链表反转
 * *****************************/

#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "type.h"

/* 创建链表 */
LNode * create_list() {
    LNode *head = (LNode *) malloc(sizeof(LNode));
    if(head == NULL) {
        printf("memeory alloc failed!");
        exit(0);
    }
    head->next = NULL;
}

/* 插入元素 */
LNode *list_append(int value, LNode *pos) {
    LNode *node = (LNode *) malloc(sizeof(LNode));
    if(node == NULL) {
        exit(0);
    }
    node->value = value;
    node->next = pos->next;
    pos->next = node;
    return node;
}

/*  打印链表 */
void list_print(LNode *list) {
    while( (list = list->next) != NULL) {
        printf("%d -> ", list->value);
    }
    printf("\n");
}

/* 反转链表 */
LNode *list_revert(LNode *node) {
    if(node->next == NULL) {
        return node;
    }
    LNode *head = list_revert(node->next);
    LNode *end = node->next;
    end->next = node;
    node->next = NULL;
    return head;
}

void list_test() {
    LNode *list = create_list();

    /* 随机数链表 */
    int i=0;
    srand(time(NULL));
    LNode *node = list;
    for(; i<10; i++) {
        node = list_append(rand(), node);
    }
    list_print(list);

    /* 链表反转 */
    list->next = list_revert(list->next);
    list_print(list);
}

#endif
