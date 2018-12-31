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
#define N 4
#define W 2
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
    int mainTime, remainTasks = N + N;  //ʱ���ᡢʣ����������
    Process test[N + N], disp[N + N];       //��Ҫ��ִ�еĽ�����
    int pt, i, j;                   //������������
    bool cpu = false;               //�Ƿ���������ִ��
    int cpuTime = 0;                //��ǰ�����ѽ��е�ʱ��
    Process inCpu;                  //��cpu��ִ�е�����
    getchar();
    cout << "-----------------------------------------------------" << endl;
//    �����ʼ��һ������
    for(i = 0; i < N; i++) {
        pt = 1 + rand() % 10;
        test[i].set(i+1, pt);
        test[i].show();
    }
//    �������ʼ��һ�Ѵ����������
    for(i = N; i < N + N; i++) {
        pt = 1 + rand() % 10;
        test[i].set(i + 1, pt);
        test[i].show();
    }
    cout << "-----------------------------------------------------" << endl;

//    Heap minHeap(test, sizeof(test)/sizeof(test[0])); //�������ˡ���Ϣ��

//    �Ȱѳ�ʼ������д�����С�ѹ��ɵ����ȶ���
    Heap minHeap;
    for(i = 0; i < N; i++) {
        minHeap.Push(test[i]);
    }

//    ֱ�Ӳ鿴����
//    minHeap.show();
//
//    ��˳��鿴��
//    for(i = 0; i < N; i++) {
//        minHeap.Top().show();
//        minHeap.Pop();
//    }

    cout << "Random Tasks Generated!" << endl;

//    ��ʼ����
    int k = 0;
    cout << "Start scheduling!  ......\n" << endl;
    for (mainTime = 1; remainTasks > 0; mainTime++) {
        cout << "\nNow time is: " << mainTime << "s." << endl;

        Start:
		if (!cpu) {     //�����ǰû����������
            cpu = true;
            inCpu = minHeap.Top();
            cout << "No." << inCpu.no << "start!!! \n";
            inCpu.t -= (mainTime - 1);
            if(inCpu.t < 0) inCpu.t = 0;
            disp[k] = inCpu;
            disp[k].start = mainTime;
            minHeap.Pop();
            if (inCpu.t == 0) goto EndJudge;    //����������Ѿ��ǵȲ���ȥ(t==0)������Ļ���
        } else {    //�����ǰ����������
		    EndJudge:
            cpuTime++;
            if (cpuTime >= inCpu.t) {   //�������
                cout << "No." << inCpu.no <<" complete!!! \n";
                cpu = false;
                remainTasks--;
                disp[k].end = mainTime;
                k++;
                cpuTime = 0;
                if (remainTasks > 0) goto Start;    //�������������Ҫ���ж�һ����һ����
            }
        }
        if (remainTasks == N + W) { //�ڵ�ǰ������ʣ�಻�� W �������ʱ�򣬲���ʣ�������(W < N)
            for(i = N; i < N + N; i++) {
                minHeap.Push(test[i]);
            }
        }
        Sleep(1000);
    }

//    ���չʾ����������������
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
