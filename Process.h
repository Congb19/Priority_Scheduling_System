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
    void display();
    int no;//编号
    int t;//长度
    int p;//优先级
    int start;//开始时间
    int end;//结束时间
    int wait;//等待时间
    Process &operator =(const Process &);
private:


};


#endif //PRIORITY_SCHEDULING_SYSTEM_PROCESS_H

