//
// Created by 20852 on 2026/1/5.
//

#include "../Inc/Heap.h"
#include <iostream>
#include <stdexcept>

Heap::Heap() {}

Heap::Heap(const std::vector<int>& data)
    : heap(data) {
    buildHeap();
}

Heap::~Heap() {
    clear();
}

void Heap::buildHeap() {
    for (int i = (heap.size() - 2) / 2; i >= 0; --i) {
        _siftDown(i);
    }
}

void Heap::_siftDown(int parent) {
    int size = heap.size();
    int child = parent * 2 + 1;

    while (child < size) {
        if (child + 1 < size && heap[child + 1] > heap[child]) {
            child++;
        }

        if (heap[parent] >= heap[child]) {
            break;
        }

        std::swap(heap[parent], heap[child]);

        parent = child;
        child = parent * 2 + 1;
    }
}

void Heap::_siftUp(int child) {
    int parent = (child - 1) / 2;

    while (child > 0 && heap[child] > heap[parent]) {
        std::swap(heap[child], heap[parent]);
        child = parent;
        parent = (child - 1) / 2;
    }
}

void Heap::push(int value) {
    heap.push_back(value);
    _siftUp(heap.size() - 1);
}

bool Heap::pop() {
    if (heap.empty()) {
        return false;
    }

    std::swap(heap[0], heap.back());
    heap.pop_back();

    if (!heap.empty()) {
        _siftDown(0);
    }
    return true;
}

int Heap::top() const {
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    return heap[0];
}

bool Heap::empty() const {
    return heap.empty();
}

int Heap::size() const {
    return heap.size();
}

void Heap::clear() {
    heap.clear();
}

void Heap::print() const {
    for (int x : heap) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
