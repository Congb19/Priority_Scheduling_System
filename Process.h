//
// Created by Congb on 2018/12/29.
//

#ifndef PRIORITY_SCHEDULING_SYSTEM_PROCESS_H
#define PRIORITY_SCHEDULING_SYSTEM_PROCESS_H

#include <iostream>
using namespace std;

class Process {
public:
    Process() {};
    Process(int, int);
    void set(int, int);
    void show();
    int no;//���
    int t;//����
    int p;//���ȼ�
    int start;//��ʼʱ��
    int end;//����ʱ��
private:


};


#endif //PRIORITY_SCHEDULING_SYSTEM_PROCESS_H

