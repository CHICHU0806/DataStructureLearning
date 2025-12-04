//
// Created by 20852 on 2025/12/5.
//

#include "../Inc/LinkedQueue.h"
#include <iostream>
using namespace std;

LnkQueue::LnkQueue() : front(nullptr), rear(nullptr) {}

LnkQueue::~LnkQueue() {
    clear();
}

bool LnkQueue::isEmpty() const {
    return front == nullptr;
}

bool LnkQueue::enqueue(int x) {
    Node* newNode = new Node(x);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    return true;
}

bool LnkQueue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty, dequeue failed." << std::endl;
        return false;
    }
    Node* p = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr; // 队列为空时更新 rear
    }
    delete p;
    return true;
}

bool LnkQueue::getFront(int &x) const {
    if (isEmpty()) {
        std::cout << "Queue is empty, no front value." << std::endl;
        return false;
    }
    x = front->data;
    return true;
}

void LnkQueue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

void LnkQueue::print() const {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    Node* current = front;
    std::cout << "Queue (front -> rear): ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
