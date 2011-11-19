百度蚂蚁题的C语言递归解法
=========================

百度笔试有一道蚂蚁题：有一根27cm的细木杆，在第3cm、7cm、11cm、17cm、23cm这五个位置上各有一只蚂蚁。木杆很细，不能同时通过一只蚂蚁。开始时，蚂蚁的头朝左还是朝右是任意的，它们只会朝前走或掉头，但不会后退。当任意两只蚂蚁碰头时，两只蚂蚁会同时掉头朝反方向走。假设蚂蚁们每秒钟可以走1cm的距离。编写程序，求所有蚂蚁都离开木杆的最小时间和最大时间。

分析：事件有两种：相撞；出杆。
相撞的话，掉头。
出杆的话，删掉。但也可保留，这影响循环结束的判断条件。
用数组实现。

定义蚂蚁：

.. sourcecode:: c

    typedef struct {
        int pos;
        int dir;
    } ant_s;
    typedef ant_s* ant;

计算时间：

.. sourcecode:: c

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
            /* 现在left,right是最近要相遇的蚂蚁位置，t是相遇时间 \*/
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

