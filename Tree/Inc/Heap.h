//
// Created by 20852 on 2026/1/5.
//

#ifndef DATASTRUCTANDALGORITHMLEARING_HEAP_H
#define DATASTRUCTANDALGORITHMLEARING_HEAP_H


#include <vector>

class Heap {
public:
    Heap();
    explicit Heap(const std::vector<int>& data);
    ~Heap();

    void buildHeap();
    void push(int value);
    bool pop();
    int top() const;
    bool empty() const;
    int size() const;
    void clear();

    void print() const;

private:
    std::vector<int> heap;

    void _siftDown(int parent);
    void _siftUp(int child);
};


#endif //DATASTRUCTANDALGORITHMLEARING_HEAP_H