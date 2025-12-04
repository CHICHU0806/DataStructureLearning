//
// Created by 20852 on 2025/12/4.
//

#include "../Inc/LnkStack.h"
#include <iostream>
using namespace std;

LnkStack::LnkStack() {
    top = nullptr;
}

LnkStack::~LnkStack() {
    clear();
}

bool LnkStack::isEmpty() const {
    return top == nullptr;
}

bool LnkStack::push(int x) {
    Node* newNode = new Node(x, top);
    top = newNode;
    return true;
}

bool LnkStack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty, pop failed." << endl;
        return false;
    }

    Node* p = top;
    top = top->next;
    delete p;
    return true;
}

bool LnkStack::topValue(int &x) const {
    if (isEmpty()) {
        cout << "Stack is empty, no top value." << endl;
        return false;
    }
    x = top->data;
    return true;
}

void LnkStack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void LnkStack::print() const {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Stack (top -> bottom): ";
    Node* p = top;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
