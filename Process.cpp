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
    cout << "priority: "<< p << endl;
    cout << "start at: " << start << endl;
    cout << "end at: " << end << endl;
    cout << "length: " << t << endl;
}