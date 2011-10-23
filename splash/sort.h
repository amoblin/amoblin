#include <stdio.h>
#include <stdlib.h>

#include "type.h"
#include "utils.h"

/* 14寸屏显示32个,完美 */
#define LEN 32
#define MAX 99

void print_array(element array[], int n) {
    int i=0;
    for(; i<n; i++) {
        printf("%2d ", array[i]);
    }
    printf("\n");
}

/* 插入排序 */
void insertion_sort(element array[], int n) {
    int i,j;
    element next;
    for( i=0; i<n; i++) {
        next = array[i];
        /* 可以用二分查找 */
        for( j=i; j>0 && next.value < array[j-1].value; j--) {
            array[j] = array[j-1];
        }
        array[j] = next;
    }
}

/* 快速排序 */
void quick_sort(element array[], int left, int right) {
    int pivot, i, j;
    if( left >= right ) {
        return;
    }

    i = left;
    j = right + 1;
    pivot = array[left].value;

    do {
        /* 找到正数第一个不小于关键字的数 */
        do {
            i++;
        } while( array[i].value < pivot );

        /* 找到倒数第一个不大于关键字的数 */
        do {
            j--;
        } while( array[j].value > pivot );

        if( i < j ) {
            swap(array[i].value, array[j].value);
        }
    } while( i < j );

    /* 这里发现了无临时变量交换两数的bug, 在参数为同一变量时. */
    if(left != j) {
        swap(array[left].value, array[j].value);
    }
    print_array(array, LEN);
    quick_sort(array, left, j-1);
    quick_sort(array, j+1, right);
}

/* 冒泡排序:先冒最小的 */
void bubble_sort(element array[], int n) {
    int i=0;
    int j;
    for(; i<n; i++) {
        for(j=n-1; j>i; j--) {
            if( array[j-1].value > array[j].value ) {
                swap(array[j-1].value, array[j].value);
            }
        }
    }
}

void test_sort() {
    element array[LEN];
    srand(time(NULL));
    int i=0;
    for(; i<LEN; i++) {
        array[i].value = rand() % MAX;
    }

    print_array(array, LEN);
    //bubble_sort(array, LEN);
    //insertion_sort(array, LEN);
    quick_sort(array, 0, LEN-1);
    print_array(array, LEN);
}
