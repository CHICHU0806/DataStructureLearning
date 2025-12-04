//
// Created by 20852 on 2025/12/5.
//

#ifndef DATASTRUCTANDALGORITHMLEARING_LINKEDQUEUE_H
#define DATASTRUCTANDALGORITHMLEARING_LINKEDQUEUE_H

class LnkQueue {
public:
    LnkQueue();
    ~LnkQueue();

    bool isEmpty() const;
    bool enqueue(int x);  // 入队
    bool dequeue();       // 出队
    bool getFront(int &x) const;
    void clear();
    void print() const;

private:
    struct Node {
        int data;
        Node* next;
        Node(int d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* front;  // 队头
    Node* rear;   // 队尾

};



#endif //DATASTRUCTANDALGORITHMLEARING_LINKEDQUEUE_H