//
// Created by Congb on 2018/12/29.
//

#include <vector>
#include "Heap.h"
#include <iostream>
using namespace std;

void swap(Process &t1, Process &t2) {
    Process temp = t1;
    t2 = t1;
    t1 = temp;
}

Heap::Heap() {}

Heap::Heap(const Process *array, size_t size) {
    for (size_t i = 0; i < size; i++){
        //v[i] = array[i];  //����д���С�
        v.push_back(array[i]);
    }

    v.resize(size);
//    CreateHeap
    if (v.size() <= 1) return;
    for (int t = (v.size() - 1 - 1) / 2; t >= 0; t--) { // t=ִ���µ��Ĵ���
        Down(t);
    }
}

void Heap::Push(Process a) {
    v.push_back(a);
    if (v.size() < 2) return; // ����Ҫ�ϵ�
    Up(v.size() - 1); // �ؼ��������ϵ�
}

void Heap::Pop() {
    if (v.empty()) return;
    size_t last = v.size() - 1;
    swap(v[0], v[last]);
    v.pop_back();
    Down(0); // �ؼ��������µ�
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


