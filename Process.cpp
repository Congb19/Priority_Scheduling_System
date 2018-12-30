//
// Created by Congb on 2018/12/29.
//

#include "Process.h"
#include <iostream>
using namespace std;

Process::Process(int a, int b):p(b),start(0),end(0),t(b),no(a) {
//    a 编号
//    b 优先级
}

void Process::set(int a, int b) {
    start=0; end=0; t=b; p=b;
}

void Process::show() {
    cout << "No: " << no+1 ;
    cout << "priority: "<< p << endl;
    cout << "start at: " << start ;
    cout << "end at: " << end << endl;
    cout << "Total time cost: " << t << endl;
}