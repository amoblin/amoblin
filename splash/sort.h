#ifndef sort_h
#define sort_h

#include <stdio.h>
#include <stdlib.h>

#include "type.h"
#include "utils.h"

/* 14寸屏显示32个,完美 */
#define LEN 32

void set_random(element array[], int n, int max) {
    srand(time(NULL));
    int i=0;
    for(; i<n; i++) {
        array[i].value = rand() % max;
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

/* 交换元素 */
//void swap(element a, element b) {
//}

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

/* 插入排序 */
void insertion_sort(element array[], int n) {
    int i,j;
    element next;
    for( i=1; i<n; i++) {
        next = array[i];
        /* 可以用二分查找 */
        for( j=i; j>0 && next.value < array[j-1].value; j--) {
            array[j] = array[j-1];
        }
        array[j] = next;
    }
}

/* Shell排序,改进插入排序,使用变长步长.参考wikipedia, 有过之而无不及. */
void shell_sort(element array[], int n) {
    int gap=0;
    while(gap <= n) {
        gap = 3 * gap + 1;
    }
    int i,j;
    element next;
    while( gap > 0) {
        for( i = gap; i < n; i++) {
            next = array[i];
            j = i;
            while( j > (gap-1) && next.value < array[j-gap].value) {
                array[j] = array[j-gap];
                j = j - gap;
            }
            array[j] = next;
        }
        gap = (gap -1 ) / 3;
    }
}

/* 快速排序:利用关键字,分两部分,递归排序. 不稳定 */
void quick_sort(element array[], int left, int right) {
    int pivot, i, j;
    if( left >= right ) {
        return;
    }

    i = left;
    j = right + 1;

    /* 关键字的选择. */
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

/* 归并排序之:合并 */
void merge(element array[], element *temp, int left, int center, int right) {
    int i = left;
    int j = center+1;
    int k = left;
    while(i<=center && j <= right) {
        array[k] = temp[i].value < temp[j].value ? temp[i++] : temp[j++];
        k++;
    }
    while(i<=center) {
        array[k++] = temp[i++];
    }
    while(j<=right) {
        array[k++] = temp[j++];
    }
}

/* 归并排序之:分治. 这个比wikipedia的好. 避免了重复复制数组. */
void msort(element array[], element temp[], int left, int right) {
    if(left > right) {
        printf("Error!\n");
        exit(0);
    }
    /* 注意这里: 把array排序到temp. */
    if(left == right) {
        temp[left] = array[left];
        return;
    }
    int center; 
    /* 注意溢出 */
    center = (right + left) / 2;
    /* 将array中排序到temp中 */
    msort(array, temp, left, center);
    msort(array, temp, center+1, right);
    /* 将temp中merge到array中 */
    merge(array, temp, left, center, right );
}

/* 归并排序入口 */
void merge_sort(element array[], int n) {
    element *temp = malloc( n * sizeof(element) );
    if(temp != NULL) {
        msort(array, temp, 0, n-1);
        free(temp);
    } else {
        printf("Error!\n");
    }
}

/* 选择排序:选出最小值, 追加到有序部分 */
void selection_sort(element array[], int n) {
    int i,j;
    int min;
    for(i=0;i<n;i++) {
        min = i;
        for(j=i+1;j<n;j++) {
            min = ( array[j].value < array[min].value ? j : min);
        }

        if(min != i) {
            swap(array[i].value, array[min].value);
        }
    }
}

/* gnome sort. 类似kmp算法的来回. */
void gnome_sort(element array[], int n) {
    int i=0;
    while(i<n) {
        if( i==0 || array[i-1].value <= array[i].value) {
            i++;
        /* 找到第一个逆序  */
        } else {
            swap(array[i-1].value, array[i].value);
            i--;
        }
    }
}

/* 堆排序 */
#include "tree.h"
void heap_sort(element array[], int n) {
    build_max_heap(array, n);
    int i = n-1;
}

void sort(element array[], int n, int type) {
    switch(type) {
        case 'b':
            bubble_sort(array, LEN);
            break;
        case 'g':
            gnome_sort(array, LEN);
            break;
        case 'h':
            heap_sort(array, LEN);
            break;
        case 'm':
            merge_sort(array, LEN);
        case 'i':
            insertion_sort(array, LEN);
            break;
        case 'q':
            quick_sort(array, 0, LEN-1);
            break;
        case 's':
            shell_sort(array, LEN);
            break;
        case ('s'+1):
            selection_sort(array, LEN);
            break;
        default:
            break;
    }
}

void test_sort() {
    element array[LEN];
    set_random(array, LEN, MAX);
    print_array(array, LEN);

    /*
     * bubble sort: b
     * quick sort: q
     * shell sort: s
     * selection sort: s+1
     * gnome sort: g
     * merge sort: m
     * */
    int type = 'm';
    sort(array, LEN, type);
    print_array(array, LEN);
}

#endif
