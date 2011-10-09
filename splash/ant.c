#include <stdio.h>

typedef ant *ant_ptr;
typedef struct ant {
    int pos;
    int step;
    ant_ptr next;
};

typedef ant *ants;

void append(ants A, int pos) {
    ant_ptr ant = malloc( sizeof(ant) );
    ant->pos = pos;
    ant->step = 1;
    A->next = ant;
}


void calculate(ant_ptr A[]);
void set_step(ant_ptr A[], int i);

int main()
{

    /* 初始化 */
    ants A = malloc( sizeof(ant) );
    A->step = 1;
    A->pos = 3;
    append(A, 7);
    append(A, 11);
    append(A, 17);
    append(A, 23);

    set_step(A, 0);
}

void set_step(ant_ptr A[], int i) {
    if (i == 5) {
        calculate(A);
        return;
    }
    set_step(A, i+1);
    A[i]->step = -A[i]->step;
    set_step(A, i+1);
}

void calculate(ant_ptr A[]) {
    int i=0;
    int time = 0;

    int left;
    int right;
    int t=INT_MAX;

    int left_cur = -1;

    while() {
        for(; i<5; i++) {
            if(A[i]->step == 1) {
                left_cur = i;
            } else if( left_cur != -1 ){
                meet_time = ( A[i]->pos - A[left_cur]->pos ) / 2;
                if( meet_time < t ) {
                    left = left_cur;
                    right = i;
                    t = meet_time;
                }
                left_cur = -1;
            } else {
            }
        }
        /* 现在left,right是最近要相遇的蚂蚁位置，t是相遇时间 */
    }

}

void meet(ant_ptr A[], int left, int right, int *time) {
    t = ( A[right]->pos - A[left]->pos ) / 2;
    *time += t;
    A[left]->step = -A[left]->step;
    A[right]->step = -A[right]->step;
}
