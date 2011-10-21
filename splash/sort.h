#include <stdio.h>

typedef struct {
    int key;
} element;

/* 插入排序 */
void insertion_sort(element list[], int n) {
    int i,j;
    element next;
    for( i=0; i<n; i++) {
        next = list[i];
        for( j=i-1; j>0 && next.key < list[j].key; j--) {
            list[j+1] = list[j];
        }
        list[j+1] = next;
    }
}

/* 快速排序 */
void quick_sort(element list[], int left, int right) {
    int pivot, i, j;
    element temp;
    if( left >= right ) {
        return;
    }

    i = left;
    j = right + 1;
    pivot = list[left].key;

    do {
        do {
            i++;
        } while( list[i].key < pivot );

        do {
            j--;
        } while( list[j].key > pivot );

        if( i < j ) {
            swap(list[i].key, list[j].key);
        }
    } while( i < j );

    swap( list[left].key, list[j].key );
    quick_sort(list, left, j-1);
    quick_sort(list, j+1, right);
}

/* 冒泡排序 */
void bubble(elememnt list[], int n) {
    int i=0;
    int j;
    for(; i<n; i++) {

}
