//
// Created by 20852 on 2025/10/24.
//

#ifndef CONTEST_DOUBLYCIRCULARLINKEDLIST_H
#define CONTEST_DOUBLYCIRCULARLINKEDLIST_H

struct DCNode {
    int data;
    DCNode* prev;
    DCNode* next;

    explicit DCNode(int val = 0) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyCircularLinkedList {
public:
    DoublyCircularLinkedList();  // 构造
    ~DoublyCircularLinkedList(); // 析构

    int size() const;
    bool insert(int pos, int value);
    bool remove(int pos);
    int get(int pos) const;
    int find(int value) const;
    void printForward() const;      // 正序打印
    void printBackward() const;     // 逆序打印

private:
    DCNode* head;  // 哨兵节点
    int length;   // 有效节点数量
};


#endif //CONTEST_DOUBLYCIRCULARLINKEDLIST_H