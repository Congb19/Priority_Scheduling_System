//
// Created by Congb on 2018/12/29.
//

#include "Process.h"
#include <iostream>
using namespace std;

Process::Process(int a, int b):p(b),start(0),end(0),t(b),no(a),wait(0){
//    a ±‡∫≈
//    b ”≈œ»º∂
}

void Process::set(int a, int b) {
    t=b; p=b; no=a; start=0; end=0; wait=0;
}

void Process::show() {
    cout << "No: " << no <<", ";
    cout << "priority: "<< p << "," << endl;
    cout << "start at: " << start << "s, ";
    cout << "end at: " << end << "s, " << endl;
    cout << "Wait: " << wait << "s,  ";
    cout << "Total time cost: " << t << "s." << endl;
    cout << endl;
}

Process& Process::operator=(const Process &pp) {
    this->no = pp.no;
    this->p = pp.p;
    this->t = pp.t;
    this->start = pp.start;
    this->end = pp.end;
    this->wait = pp.wait;
    return *this;
//    Process a(pp.no, pp.p);
//    return a;
}