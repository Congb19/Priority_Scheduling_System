#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include "Process.h"
#include "Heap.h"
//
// Created by Congb on 2018/12/29.
// Heap:
//
using namespace std;
int main() {
    int time=0;
    Process test[6]={{1,2,3},{1,2,3},{1,2,3},{1,2,3},{1,2,3},{1,2,3}};
    int st,et,pt;
    //srand(time(NULL));
//随机的初始化
    for(int i = 0; i < 6; i++ ) {
        st = rand() % 10;
        et = rand() % 10;
        pt = rand() % 100;
        test[i].set(pt, st, et);
        test[i].show();
    }
//

    cout << "Hello, World!" << endl;
    return 0;
}