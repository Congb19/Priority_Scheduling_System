#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "Process.h"
#include "Heap.h"
//
// Created by Congb on 2018/12/29.
// Heap: 最小堆实现优先队列
// Process: 作业进程类
//
using namespace std;
int main() {
    cout << "****************************************" << endl;
    cout << "*------Priority Scheduling System------*" << endl;
    cout << "*----------Powered by Congb19----------*" << endl;
    cout << "*--------------2018.12.29--------------*" << endl;
    cout << "****************************************" << endl;
    int time=0;
    Process test[6]={{1,2,3}, {1,2,3},{1,2,3},{1,2,3},{1,2,3},{1,2,3}};
    int st,et,pt;
//随机的初始化
    for(int i = 0; i < 6; i++ ) {
        st = rand() % 10;
        et = rand() % 10;
        pt = rand() % 100;
        test[i].set(pt, st, et);
//        test[i].show();
    }
    Heap minheap(test, sizeof(test)/sizeof(test[0]));



    return 0;
}