#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define True 1
#define False 0

#define ANTS_NUM 5
#define LEFT -1
#define RIGHT 1

int count = 0;
int min_time = INT_MAX;
int max_time = 0;

typedef struct {
    int pos;
    int dir;
} ant_s;

typedef ant_s *ant;


int calculate(ant A[]);
void retrieve(ant A[], int i);
void walk(ant A[], int begin, int end, int t);

int main()
{

    /* 初始化 */
    ant A[ANTS_NUM];
    int i = 0;
    for(; i < 5; i++) {
        A[i] = malloc( sizeof(ant_s) );
        if(A[i] == NULL) {
            printf("Error!\n");
            exit(0);
        }
    }
    A[0]->pos = 3;
    A[1]->pos = 7;
    A[2]->pos = 11;
    A[3]->pos = 17;
    A[4]->pos = 23;

    retrieve(A, 0);

    for(; i < 5; i++) {
        free(A[i]);
    }

    printf("min time: %d, max time: %d.\n", min_time, max_time);
}

void retrieve(ant A[], int i) {
    if ( i == ANTS_NUM) {
        printf("station %d: ", count);
        int data[ANTS_NUM * 2];
        int j;
        for(j=0; j< ANTS_NUM; j++) {
            data[2 * j] = A[j]->dir;
            data[2 * j + 1] = A[j]->pos;
            printf("%d\t", A[j]->dir);
        }

        int t = calculate(A);
        min_time = t < min_time ? t : min_time;
        max_time = t > max_time ? t : max_time;

        for(j=0; j< ANTS_NUM; j++) {
            A[j]->dir= data[2 * j];
            A[j]->pos = data[2 * j + 1];
        }
        count++;
        return;
    }
    A[i]->dir = RIGHT;
    retrieve(A, i+1);
    A[i]->dir= LEFT;
    retrieve(A, i+1);
}

void walk(ant A[], int begin, int end, int t) {
    int i;
    for( i=begin; i<end; i++ ) {
        A[i]->pos += t * A[i]->dir;
    }
}

int calculate(ant A[]) {
    int i=0;
    int time = 0;

    int begin = 0;
    int end = ANTS_NUM;

    int left;
    int right;

    int left_cur = -1;
    int meet = False;
    int leave_left = False;
    int leave_right = False;
    int t = INT_MAX;

    while( begin < end ) {
        if( A[begin]->dir == -1 ) {
            if( A[begin]->pos < t) {
                t = A[begin]->pos;
                leave_left = True;
            }
        }
        if( A[end-1]->dir == 1 ) {
            int t1 = 27 - A[end-1]->pos;
            if( t1 < t ) {
                t = t1;
                leave_right = True;
                leave_left = False;
            }
        }
        int i=begin;
        for(; i<end; i++) {
            if(A[i]->dir == 1) {
                left_cur = i;
            } else if( left_cur != -1){
                int meet_time = ( A[i]->pos - A[left_cur]->pos ) / 2;
                if( meet_time < t ) {
                    meet = True;
                    leave_left = False;
                    leave_right = False;
                    left = left_cur;
                    right = i;
                    t = meet_time;
                }
                left_cur = -1;
            } else {
            }
        }
        /* 现在left,right是最近要相遇的蚂蚁位置，t是相遇时间 */
        time += t;
        walk(A, begin, end, t);
        if(meet) {
            A[left]->dir = LEFT ;
            A[right]->dir = RIGHT;
        }
        if(leave_left) {
            begin++;
        }
        if(leave_right) {
            end--;
        }

        left_cur = -1;
        meet = False;
        leave_left = False;
        leave_right = False;
        t = INT_MAX;
    }
    printf("time: %d\n", time);
    return time;
}
