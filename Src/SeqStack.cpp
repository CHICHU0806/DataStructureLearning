//
// Created by 20852 on 2025/10/24.
//

#include "../Inc/SeqStack.h"
#include <iostream>
using namespace std;

// 构造函数
SeqStack::SeqStack(int size) {
    maxSize = size;
    data = new int[maxSize];
    top = -1;
}

// 析构函数
SeqStack::~SeqStack() {
    delete[] data;
}

bool SeqStack::isEmpty() const {
    return top == -1;
}

bool SeqStack::isFull() const {
    return top == maxSize - 1;
}

bool SeqStack::push(int x) {
    if (isFull()) {
        cout << "Stack is full,push failed." << endl;
        return false;
    }
    data[++top] = x;

    return true;
}

bool SeqStack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty,pop failed." << endl;
        return false;
    }
    top--;
    return true;
}

bool SeqStack::topValue(int &x) const {
    if (isEmpty()) {
        cout << "Stack is empty,there is no pop parameter。" << endl;
        return false;
    }
    x = data[top];
    return true;
}

void SeqStack::clear() {
    top = -1;
}

void SeqStack::print() const {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Stack Content(from bottom to top):";
    for (int i = 0; i <= top; i++) {
        cout << data[i] << " ";
    }
    cout << endl;Stack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is emptyStack is empty
}
