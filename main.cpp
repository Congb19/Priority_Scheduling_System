//
// Created by Congb on 2018/12/29.
// Heap: ��С��ʵ�����ȶ���
// Process: ��ҵ������
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
    int mainTime, remainTasks = N;  //ʱ���ᡢʣ����������
    Process test[N], disp[N];       //��Ҫ��ִ�еĽ�����
    int pt, i, j;                   //������������
    bool cpu = false;               //�Ƿ���������ִ��
    int cpuTime = 0;                //��ǰ�����ѽ��е�ʱ��
    Process inCpu;                  //��cpu��ִ�е�����

//    �����ʼ��һ������
    for(i = 0; i < N; i++) {
        pt = 1 + rand() % 10;
        test[i].set(i+1, pt);
        test[i].show();
    }

//    ������С�ѹ��ɵ����ȶ���
    Heap minHeap(test, sizeof(test)/sizeof(test[0]));
    for(i = 0; i < N; i++) {
        minHeap.Top().show();
        minHeap.Pop();
    }
    cout << "Random Tasks Generated!" << endl;

////    ��ʼ����
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
////    ���չʾ����������������
//    for (j = 0; j < N; j++) {
//        cout << "The " << j+1 << "Completion Process: " << endl;
//        disp[j].show();
//    }

    cout << "Missions complete!" << endl;
    return 0;
}
