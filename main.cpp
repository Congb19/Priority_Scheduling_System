//
// Created by Congb on 2018/12/29.
// Heap: ��С��ʵ�����ȶ���
// Process: ��ҵ������
//
// ���޸�encodingΪGBK�����������Ķ�ע�͡�
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
    int mainTime, cutInTime = 0, remainTasks = N + N, comTasks = 0;  //ʱ���ᡢʣ����������
    Process test[N + N], disp[N + N];       //��Ҫ��ִ�еĽ�����
    int pt, i, j;                           //������������
    bool cpu = false;                       //�Ƿ���������ִ��
    int cpuTime = 0;                        //��ǰ�����ѽ��е�ʱ��
    Process inCpu;                          //��cpu��ִ�е�����
    int cutIn = 0;                          //�Ƿ��Ѿ�����ʣ������

    getchar();
    cout << "-----------------------------------------------------" << endl;
//    �����ʼ��һ������
    for(i = 0; i < N; i ++) {
        pt = 2 + rand() % 5;
        test[i].set(i+1, pt);
        test[i].display();
    }
//    �������ʼ��һ�� �����������
    for(i = N; i < N + N; i ++) {
        pt = 2 + rand() % 5;
        test[i].set(i + 1, pt);
        test[i].display();
    }
    cout << "-----------------------------------------------------" << endl;

//    �������ˡ���Ϣ��
//    Heap minHeap(test, sizeof(test)/sizeof(test[0]));

//    �ѳ�ʼ������д�����С�ѹ��ɵ����ȶ���
    Heap minHeap;
    for(i = 0; i < N; i ++) {
        minHeap.Push(test[i]);
    }

//    �������á�
//    ֱ�Ӳ鿴����
//    minHeap.show();
//
//    ��˳��鿴��
//    for(i = 0; i < N; i++) {
//        minHeap.Top().show();
//        minHeap.Pop();
//    }

    cout << "Random Tasks Created!" << endl;

//    ��ʼ����
    int k = 0;
    cout << "Start scheduling!  ......\n" << endl;
    for (mainTime = 1; remainTasks > 0; mainTime ++) {
        cout << "\nNow time is the start of: " << mainTime << "s." << endl;
//        ʵʱ�������ȼ���
//        for���Ѿ����Ż��ˡ���Ϣ��
//        for (int l = 0; l < minHeap.Size(); ++l) {
//            test[l].p --;
//            if (test[l].p < 0) test[l].p = 0;
//            if (l == N - 1 && cutIn == 0) break;
//        }
//      �ڵ�ǰ������ʣ�಻��W��������û�в�����Ļ�������ʣ�������(W < N)
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
		if (!cpu) {     //�����ǰû����������
            cpu = true;
            inCpu = minHeap.Top();
            cout << "No." << inCpu.no << " start!!! \n";
////          �ɵķ����������Ժ�������ȼ������ѱ�֤������bug�����Ż���
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
        } else {    //�����ǰ����������
            cpuTime++;
            if (cpuTime >= inCpu.t) {   //��ǰ���������
                cout << "No." << inCpu.no <<" complete!!! \n";
                cpu = false;
                remainTasks --;
                comTasks ++;
                disp[k].end = mainTime;
                k ++;
                cpuTime = 0;
                if (remainTasks > 0) goto Start;    //�������������Ҫ���ж�һ����һ�롣
            }
        }
        minHeap.update();
        Sleep(100);
    }

//    ���չʾ����������������
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
