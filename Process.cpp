//
// Created by Congb on 2018/12/29.
//

#include "Process.h"
#include <iostream>
using namespace std;

Process::Process(int a, int b, int c):p(a),start(b),end(c),t(c-b) {
    //
}

void Process::set(int a, int b, int c) {
    p=a; start=b; end=c; t=c-b;
}

void Process::show() {
    cout << "priority: ";
    cout << p << endl;
    //cout<<"开始时间："<<start<<endl;
    //cout<<"结束时间："<<end<<endl;
    //cout<<"长度："<<t<<endl;
}