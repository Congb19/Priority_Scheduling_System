//
// Created by Congb on 2018/12/29.
// Heap: 最小堆实现优先队列
// Process: 作业进程类
//
// 请修改encoding为GBK，可以正常阅读注释。
//
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <windows.h>
#include <time.h>
#include "Process.h"
#include "Heap.h"
#define N 4 //每组任务个数
#define W 2 //剩余W的时候插入新任务
//W < N.
using namespace std;

int main() {
    cout << endl;
    cout << "****************************************" << endl;
    cout << "*------Priority Scheduling System------*" << endl;
    cout << "*----------Powered by Congb19----------*" << endl;
    cout << "*--------------2018.12.29--------------*" << endl;
    cout << "****************************************" << endl;
    cout << "Press \"Enter\" to start." << endl;

    srand(time(NULL));
    int mainTime, cutInTime = 0, remainTasks = N + N, comTasks = 0;  //时间轴、剩余任务数量
    Process test[N + N], disp[N + N];       //将要被执行的进程组
    int pt, i, j;                           //存放随机优先数
    bool cpu = false;                       //是否有任务在执行
    int cpuTime = 0;                        //当前任务已进行的时间
    Process inCpu;                          //在cpu中执行的任务
    int cutIn = 0;                          //是否已经插入剩余任务

    getchar();
    cout << "-----------------------------------------------------" << endl;
//    随机初始化一堆任务
    for(i = 0; i < N; i ++) {
        pt = 2 + rand() % 5;
        test[i].set(i+1, pt);
        test[i].display();
    }
//    再随机初始化一堆 待插入的任务
    for(i = N; i < N + N; i ++) {
        pt = 2 + rand() % 5;
        test[i].set(i + 1, pt);
        test[i].display();
    }
    cout << "-----------------------------------------------------" << endl;

//    换方案了。安息吧
//    Heap minHeap(test, sizeof(test)/sizeof(test[0]));

//    把初始任务队列存入最小堆构成的优先队列
    Heap minHeap;
    for(i = 0; i < N; i ++) {
        minHeap.Push(test[i]);
    }

//    。测试用。
//    直接查看向量
//    minHeap.show();
//
//    按顺序查看堆
//    for(i = 0; i < N; i++) {
//        minHeap.Top().show();
//        minHeap.Pop();
//    }

    cout << "Random Tasks Created!" << endl;

//    开始进程
    int k = 0;
    cout << "Start scheduling!  ......\n" << endl;
    for (mainTime = 1; remainTasks > 0; mainTime ++) {
        cout << "\nNow time is the start of: " << mainTime << "s." << endl;
//        实时更新优先级。
//        for你已经被优化了。安息。
//        for (int l = 0; l < minHeap.Size(); ++l) {
//            test[l].p --;
//            if (test[l].p < 0) test[l].p = 0;
//            if (l == N - 1 && cutIn == 0) break;
//        }
//      在当前队列中剩余不到W个任务且没有插入过的话，插入剩余的任务。(W < N)
        if (remainTasks == N + W && cutIn == 0) {
            cout << N << " new missions cut in *&*&*&*&*&*&*&*&. \n";
            for(i = N; i < N + N; i++) {
                minHeap.Push(test[i]);
//                cout << "No: " << i + 1 << " cut in. \n";
            }
            cutIn ++;
            cutInTime = mainTime;
            cout << " cutInTime: " << cutInTime << " s. \n";
        }
        Start:
		if (!cpu) {     //如果当前没有任务在跑
            cpu = true;
            inCpu = minHeap.Top();
            cout << "No." << inCpu.no << " start!!! \n";
////          旧的方案（进来以后更新优先级）。已被证明存在bug，已优化。
//            if (inCpu.no < N + 1) {
//                inCpu.wait = (mainTime - 1);
////                inCpu.p -= inCpu.wait;
//            }
//            else {
//                inCpu.wait = (mainTime - cutInTime + 1);
////                inCpu.p -= inCpu.wait;
//            }
////            if(inCpu.p < 0) inCpu.p = 0;
            disp[k] = inCpu;
            disp[k].start = mainTime;
            minHeap.Pop();
        } else {    //如果当前有任务在跑
            cpuTime++;
            if (cpuTime >= inCpu.t) {   //当前的运算结束
                cout << "No." << inCpu.no <<" complete!!! \n";
                cpu = false;
                remainTasks --;
                comTasks ++;
                disp[k].end = mainTime;
                k ++;
                cpuTime = 0;
                if (remainTasks > 0) goto Start;    //如果还有任务，需要再判断一遍这一秒。
            }
        }
        minHeap.update();
        Sleep(100);
    }

//    最后展示所有任务的运行情况
    cout << "-----------------------------------------------------" << endl;
    for (j = 0; j < N + N; j ++) {
        if (j == 0) cout << "The 1st" << " Completion Process: " << endl;
        else if (j == 1) cout << "The 2nd" << " Completion Process: " << endl;
        else if (j == 2) cout << "The 3rd" << " Completion Process: " << endl;
        else cout << "The " << j + 1 << "th Completion Process: " << endl;
        disp[j].show();
    }

    cout << "Missions complete! \nTotal time cost: " << mainTime - 2 << "s." << endl;
    return 0;
}
