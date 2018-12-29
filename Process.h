//
// Created by Congb on 2018/12/29.
//

#ifndef PRIORITY_SCHEDULING_SYSTEM_PROCESS_H
#define PRIORITY_SCHEDULING_SYSTEM_PROCESS_H


class Process {
public:
    Process(int, int, int);
    void set(int, int, int);
    void show();
private:
    int t;//长度
    int p;//优先级
    int start;//开始时间
    int end;//结束时间

};


#endif //PRIORITY_SCHEDULING_SYSTEM_PROCESS_H
