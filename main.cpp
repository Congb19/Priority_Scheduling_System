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
#define N 4 //ÿ���������
#define W 2 //ʣ��W��ʱ�����������
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
    int mainTime, cutInTime = 0, remainTasks = N + N;  //ʱ���ᡢʣ����������
    Process test[N + N], disp[N + N];       //��Ҫ��ִ�еĽ�����
    int pt, i, j;                   //������������
    bool cpu = false;               //�Ƿ���������ִ��
    int cpuTime = 0;                //��ǰ�����ѽ��е�ʱ��
    Process inCpu;                  //��cpu��ִ�е�����
    int cutIn = 0;
    getchar();
    cout << "-----------------------------------------------------" << endl;
//    �����ʼ��һ������
    for(i = 0; i < N; i++) {
        pt = 1 + rand() % 6;
        test[i].set(i+1, pt);
        test[i].show();
    }
//    �������ʼ��һ�Ѵ����������
    for(i = N; i < N + N; i++) {
        pt = 1 + rand() % 6;
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
        if (remainTasks == N + W && cutIn == 0) { //�ڵ�ǰ������ʣ�಻��W��������û�в�����Ļ�������ʣ�������(W < N)
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
		if (!cpu) {     //�����ǰû����������
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
            //if (inCpu.p == 0) goto EndJudge;    //����������Ѿ��ǵȲ���ȥ(t==0)������Ļ���
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
