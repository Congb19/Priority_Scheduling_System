//
// Created by Congb on 2018/12/29.
//

#ifndef PRIORITY_SCHEDULING_SYSTEM_HEAP_H
#define PRIORITY_SCHEDULING_SYSTEM_HEAP_H

#include <vector>
#include "Process.h"
#include <iostream>
using namespace std;

class Heap {
public:
    Heap();
    Heap(const Process* array, size_t size);
    void Push(Process a);
    void Pop();
//Ò»Ð©º¯Êý
//    bool Empty() const {
//        return v.empty();
//    }
    size_t Size() const {
        return v.size();
    }
    Process Top() {
        return v[0];
    }
    void show() {
        for (int i = 0; i < v.size(); ++i) {
            v[i].show();
        }
    }
    void update();

private:
    vector<Process> v;
    void Down(size_t r);
    void Up(size_t loc);

};


#endif //PRIORITY_SCHEDULING_SYSTEM_HEAP_H

