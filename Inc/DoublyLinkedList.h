//
// Created by 20852 on 2025/10/23.
//

#ifndef CONTEST_DOUBLYLINKEDLIST_H
#define CONTEST_DOUBLYLINKEDLIST_H

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    explicit DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    int size() const;
    bool insert(int pos, int val);  // 按位置插入
    bool remove(int pos);           // 按位置删除
    int get(int pos) const;         // 按位置读取
    int find(int val) const;        // 按值查找
    void printForward() const;      // 正序打印
    void printBackward() const;     // 逆序打印

private:
    DNode* head;
    DNode* tail;
    int length;
};


#endif //CONTEST_DOUBLYLINKEDLIST_H