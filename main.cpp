//
// Created by Congb on 2018/12/29.
// Heap: 最小堆实现优先队列
// Process: 作业进程类
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "Process.h"
#include "Heap.h"
#include <windows.h>
#include <time.h>
#define N 6

using namespace std;

int main() {
    cout << endl;
    cout << "****************************************" << endl;
    cout << "*------Priority Scheduling System------*" << endl;
    cout << "*----------Powered by Congb19----------*" << endl;
    cout << "*--------------2018.12.29--------------*" << endl;
    cout << "****************************************" << endl;

    srand(time(NULL));
    int maintime, remaintasks = N;//时间轴、剩余任务数量
    Process test[N];//将要被执行的进程组
    int pt = 0;//存放随机优先数
    bool cpu = false;//是否有任务在执行
    int cputime = 0;//当前任务已进行的时间
    Process incpu;//在cpu中执行的任务

//    随机初始化一堆任务
    for(int i = 0; i < N; i++ ) {
        pt = rand() % 100;
        test[i].set(i, pt);
        test[i].show();
    }

//    存入最小堆构成的优先队列
    Heap minheap(test, sizeof(test)/sizeof(test[0]));
    cout << "Random Tasks Generated!" << endl;

//    开始进程
    int k = 0;
    cout << "Start scheduling!  ......" << endl;
    for (maintime = 1; remaintasks <= 0; maintime++) {
        cout << "Now time is: " << maintime << "s." << endl;
        if (!cpu) {
            cpu = true;
            incpu = minheap.Top();
            incpu.t -= maintime;
            test[k] = incpu;
            test[k].start = maintime;
            minheap.Pop();
        } else {
            cputime++;
            if (cputime == incpu.t) {
                remaintasks--;
                cpu = false;
                test[k].end = maintime;
                k++;
                cputime = 0;
            }
        }
        Sleep(1000);
    }

//    最后展示所有任务的运行情况
    for (int j = 0; j < N; j++) {
        cout << "The " << j+1 << "Completion Process: " << endl;
        test[j].show();
    }

    cout << "Missions complete!" << endl;
    return 0;
}