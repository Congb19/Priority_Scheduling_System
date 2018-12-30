//
// Created by Congb on 2018/12/29.
// Heap: 最小堆实现优先队列
// Process: 作业进程类
//
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <windows.h>
#include <time.h>
#include "Process.h"
#include "Heap.h"
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
    int mainTime, remainTasks = N;  //时间轴、剩余任务数量
    Process test[N], disp[N];       //将要被执行的进程组
    int pt, i, j;                   //存放随机优先数
    bool cpu = false;               //是否有任务在执行
    int cpuTime = 0;                //当前任务已进行的时间
    Process inCpu;                  //在cpu中执行的任务

//    随机初始化一堆任务
    for(i = 0; i < N; i++) {
        pt = 1 + rand() % 10;
        test[i].set(i+1, pt);
        test[i].show();
    }

//    存入最小堆构成的优先队列
    Heap minHeap(test, sizeof(test)/sizeof(test[0]));
    for(i = 0; i < N; i++) {
        minHeap.Top().show();
        minHeap.Pop();
    }
    cout << "Random Tasks Generated!" << endl;

////    开始进程
//    int k = 0;
//    cout << "Start scheduling!  ......\n" << endl;
//    for (mainTime = 1; remainTasks > 0; mainTime++) {
//        cout << "Now time is: " << mainTime << "s." << endl;
//        Again:
//		if (!cpu) {
//			remainTasks--;
//    		cout<<"youyigerenwukaishile.**********.\n";
//            cpu = true;
//            inCpu = minHeap.Top();
//            inCpu.t -= (mainTime - 1);
//            if(inCpu.t < 0) inCpu.t = 0;
//            disp[k] = inCpu;
//            disp[k].start = mainTime;
//            minHeap.Pop();
//        } else {
//            if (cpuTime == inCpu.t) {
//                cout<<"youyigerenwuwanchengle.**********.\n";
//                cpu = false;
//                disp[k].end = mainTime;
//                k++;
//                cpuTime = 0;
//                goto Again;
//            }
//            cpuTime++;
//        }
//        Sleep(1000);
//    }
//
////    最后展示所有任务的运行情况
//    for (j = 0; j < N; j++) {
//        cout << "The " << j+1 << "Completion Process: " << endl;
//        disp[j].show();
//    }

    cout << "Missions complete!" << endl;
    return 0;
}
