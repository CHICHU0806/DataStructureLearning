//
// Created by 20852 on 2025/12/5.
//

#ifndef DATASTRUCTANDALGORITHMLEARING_SEQQUEUE_H
#define DATASTRUCTANDALGORITHMLEARING_SEQQUEUE_H

class SeqQueue {
public:
    SeqQueue(int size = 100);   // 构造
    ~SeqQueue();                // 析构

    bool isEmpty() const;
    bool isFull() const;

    bool enqueue(int x);        // 入队
    bool dequeue();             // 出队
    bool getFront(int& x) const;// 获取队头

    void clear();
    void print() const;

private:
    int* data;       // 顺序存储空间
    int front;       // 队头
    int rear;        // 队尾
    int maxSize;     // 容量
};

#endif //DATASTRUCTANDALGORITHMLEARING_SEQQUEUE_H