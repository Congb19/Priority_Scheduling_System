//
// Created by Congb on 2018/12/29.
//

#include <vector>
#include "Heap.h"
#include <iostream>
using namespace std;

Heap::Heap() {}

Heap::Heap(const Process *array, size_t size) {
    for (size_t i = 0; i < size; i++){
        v[i] = array[i];
    }
    v.resize(size);
//    CreateHeap
    if (v.size() <= 1) return;
    for (int t = (v.size() - 1 - 1) / 2; t >= 0; t--) { // t=执行下调的次数
        Down(t);
    }
}

void Heap::Push(Process a) {
    v.push_back(a);
    if (v.size() < 2) return; // 不需要上调
    Up(v.size() - 1); // 秘技！无限上调
}

void Heap::Pop() {
    if (v.empty()) return;
    size_t last = v.size() - 1;
    swap(v[0], v[last]);
    v.pop_back();
    Down(0); // 秘技！无限下调
}

void Heap::Down(size_t r) {
    size_t c = r * 2 + 1;
    while (c < v.size()) {
        if (c + 1 < v.size() && v[c].p < v[c+1].p)
            c++;
        if(v[r].p > v[c].p) {
            swap(v[r], v[c]);
            r = c;
            c = 2 * r + 1;
        }
        else return;
    }
}

void Heap::Up(size_t loc) {
    size_t r = (loc - 1) / 2;
    while (loc != 0) {
        if (v[loc].p < v[r].p) {
            swap(v[loc], v[r]);
            loc = r;
            r = (loc - 1) / 2;
        }
        else return;
    }
}

