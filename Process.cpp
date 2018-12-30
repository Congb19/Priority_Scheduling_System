//
// Created by Congb on 2018/12/29.
//

#include "Process.h"
#include <iostream>
using namespace std;

Process::Process(int a, int b):p(b),start(0),end(0),t(b),no(a) {
//    a ±‡∫≈
//    b ”≈œ»º∂
}

void Process::set(int a, int b) {
    start=0; end=0; t=b; p=b; no=a;
}

void Process::show() {
    cout << "No: " << no <<", ";
    cout << "priority: "<< p << "," << endl;
    cout << "start at: " << start << ", ";
    cout << "end at: " << end << ", " << endl;
    cout << "Total time cost: " << t << "." << endl;
    cout << endl;
}
