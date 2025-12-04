//
// Created by 20852 on 2025/12/5.
//

#include "../Inc/SeqQueue.h"
#include <iostream>
using namespace std;

SeqQueue::SeqQueue(int size) {
    maxSize = size;
    data = new int[maxSize];
    front = 0;
    rear = 0;  // 队尾从 0 开始
}

SeqQueue::~SeqQueue() {
    delete[] data;
}

bool SeqQueue::isEmpty() const {
    return front == rear;
}

bool SeqQueue::isFull() const {
    return (rear + 1) % maxSize == front;
}

bool SeqQueue::enqueue(int x) {
    if (isFull()) {
        cout << "Queue is full, enqueue failed." << endl;
        return false;
    }

    data[rear] = x;
    rear = (rear + 1) % maxSize;
    return true;
}

bool SeqQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty, dequeue failed." << endl;
        return false;
    }

    front = (front + 1) % maxSize;
    return true;
}

bool SeqQueue::getFront(int &x) const {
    if (isEmpty()) {
        cout << "Queue is empty, no front value." << endl;
        return false;
    }
    x = data[front];
    return true;
}

void SeqQueue::clear() {
    front = rear = 0;
}

void SeqQueue::print() const {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue (front → rear): ";
    int i = front;
    while (i != rear) {
        cout << data[i] << " ";
        i = (i + 1) % maxSize;
    }
    cout << endl;
}
