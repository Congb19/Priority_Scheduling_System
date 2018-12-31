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
    int mainTime, cutInTime = 0, remainTasks = N + N;  //时间轴、剩余任务数量
    Process test[N + N], disp[N + N];       //将要被执行的进程组
    int pt, i, j;                   //存放随机优先数
    bool cpu = false;               //是否有任务在执行
    int cpuTime = 0;                //当前任务已进行的时间
    Process inCpu;                  //在cpu中执行的任务
    int cutIn = 0;
    getchar();
    cout << "-----------------------------------------------------" << endl;
//    随机初始化一堆任务
    for(i = 0; i < N; i++) {
        pt = 1 + rand() % 6;
        test[i].set(i+1, pt);
        test[i].show();
    }
//    再随机初始化一堆待插入的任务
    for(i = N; i < N + N; i++) {
        pt = 1 + rand() % 6;
        test[i].set(i + 1, pt);
        test[i].show();
    }
    cout << "-----------------------------------------------------" << endl;

//    Heap minHeap(test, sizeof(test)/sizeof(test[0])); //换方案了。安息吧

//    先把初始任务队列存入最小堆构成的优先队列
    Heap minHeap;
    for(i = 0; i < N; i++) {
        minHeap.Push(test[i]);
    }

//    直接查看向量
//    minHeap.show();
//
//    按顺序查看堆
//    for(i = 0; i < N; i++) {
//        minHeap.Top().show();
//        minHeap.Pop();
//    }

    cout << "Random Tasks Generated!" << endl;

//    开始进程
    int k = 0;
    cout << "Start scheduling!  ......\n" << endl;
    for (mainTime = 1; remainTasks > 0; mainTime++) {
        cout << "\nNow time is: " << mainTime << "s." << endl;
        if (remainTasks == N + W && cutIn == 0) { //在当前队列中剩余不到W个任务且没有插入过的话，插入剩余的任务。(W < N)
            cout << N << " new missions cut in. \n";
            for(i = N; i < N + N; i++) {
                minHeap.Push(test[i]);
                cout << "No: " << i + 1 << " cut in. \n";
            }
            cutIn++;
            cutInTime = mainTime;
            cout << " cutInTime: " << cutInTime << " s. \n";
        }
        Start:
		if (!cpu) {     //如果当前没有任务在跑
            cpu = true;
            inCpu = minHeap.Top();
            cout << "No." << inCpu.no << " start!!! \n";
            if (inCpu.no < N + 1) {
                inCpu.wait = (mainTime - 1);
                inCpu.p -= inCpu.wait;
            }
            else {
                inCpu.wait = (mainTime - cutInTime + 1);
                inCpu.p -= inCpu.wait;
            }
            if(inCpu.p < 0) inCpu.p = 0;
            disp[k] = inCpu;
            disp[k].start = mainTime;
            minHeap.Pop();
            //if (inCpu.p == 0) goto EndJudge;    //如果进来的已经是等不下去(t==0)的任务的话。
        } else {    //如果当前有任务在跑
		    EndJudge:
            cpuTime++;
            if (cpuTime >= inCpu.t) {   //运算结束
                cout << "No." << inCpu.no <<" complete!!! \n";
                cpu = false;
                remainTasks--;
                disp[k].end = mainTime;
                k++;
                cpuTime = 0;
                if (remainTasks > 0) goto Start;    //如果还有任务，需要再判断一遍下一个。
            }
        }

        Sleep(1000);
    }

//    最后展示所有任务的运行情况
    cout << "-----------------------------------------------------" << endl;
    for (j = 0; j < N + N; j++) {
        if (j == 0) cout << "The 1st" << " Completion Process: " << endl;
        else if (j == 1) cout << "The 2nd" << " Completion Process: " << endl;
        else if (j == 2) cout << "The 3rd" << " Completion Process: " << endl;
        else cout << "The " << j + 1 << "th Completion Process: " << endl;
        disp[j].show();
    }

    cout << "Missions complete!" << endl;
    return 0;
}
