//
// Created by Congb on 2018/12/29.
//

#include <vector>
#include "Heap.h"
#include <iostream>
using namespace std;

//void swap(Process &t1, Process &t2) {
//    Process temp = t1;
//    t2 = t1;
//    t1 = temp;
//}

Heap::Heap() {}

//这个构造函数是原本的堆构造方案。现在用不上它了。安息吧。
Heap::Heap(const Process *array, size_t size) {
    for (size_t i = 0; i < size; i++){
        //v[i] = array[i];  //这样写不行。
        v.push_back(array[i]);
        cout << "********** No." << array[i].no << " cut in!" << endl;
    }

    v.resize(size);
    cout << "v.size= " << v.size() << endl;
//    CreateHeap
    if (v.size() <= 1) return;
    for (int t = (v.size() - 1 - 1) / 2; t >= 0; t--) { // t=执行下调的次数
        Down(t);
    }
}

void Heap::Push(Process a) {
    v.push_back(a);
//    cout << "********** No." << a.no << " cut in!" << endl;
    if (v.size() < 2) return; // 不需要上调
    Up(v.size() - 1); // 秘技！无限上调
}

void Heap::Pop() {
    if (v.empty()) return;
    size_t last = v.size() - 1;
    if (v.size() > 1) swap(v[0], v[last]);
//    cout << "No." << v[last].no << " poped from heap.\n";
    v.pop_back();
    if (v.size() > 1) Down(0); // 秘技！无限下调
//    cout << "now top is No." << v[0].no << " \n";
}

void Heap::Down(size_t r) {
    size_t c = r * 2 + 1;
    while (c < v.size()) {
        if (c + 1 < v.size()) { //有两个孩子
            if (v[c].p > v[c+1].p) c++; //左 > 右
            else if (v[c].p == v[c+1].p) { //左 == 右
                if(v[c].no > v[c+1].no) c++;
            }
        }

        if(v[r].p > v[c].p) {
//            cout << "<<<<<<<<<< No." << v[r].no << " Down!" << endl;
            swap(v[r], v[c]);
            r = c;
            c = 2 * r + 1;
        }
        else if (v[r].p == v[c].p) {
//            cout << "log1\n";
            if(v[r].no > v[c].no) {
//                cout << "<<<<<<<<<< No." << v[r].no << " Down!" << endl;
                swap(v[r], v[c]);
                r = c;
                c = 2 * r + 1;
            }
            else break;
        }
        else {
            break;
        }
    }
}

void Heap::Up(size_t loc) {
    size_t r = (loc - 1) / 2;
    while (loc != 0) {
        if (v[loc].p < v[r].p) {
//            cout << ">>>>>>>>>> No." << v[loc].no << " Up!" << endl;
            swap(v[loc], v[r]);
            loc = r;
            r = (loc - 1) / 2;
        }
//        else if (v[loc].p == v[r].p) {
//            if (v[loc].no < v[r].no) {
//                cout << ">>>>>>>>>> No." << v[loc].no << " Up!" << endl;
//                swap(v[loc], v[r]);
//                loc = r;
//                r = (loc - 1) / 2;
//            }
//        }
        else return;
    }
}

void Heap::update() {
    for (int l = 0; l < v.size(); l ++) {
        v[l].p --;
        v[l].wait ++;
//        if (v[l].p < 0) v[l].p = 0;
    }
    if (v.size() > 0) cout << "updated\n";
}