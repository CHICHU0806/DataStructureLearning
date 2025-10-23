//
// Created by 20852 on 2025/10/24.
//

#ifndef CONTEST_CIRCULARLINKEDLIST_H
#define CONTEST_CIRCULARLINKEDLIST_H

struct CLLNode {
    int data;   //数据
    CLLNode* next; //指向下个节点的指针
    explicit CLLNode(int val = 0) : data(val), next(nullptr) {}
};

class CircularLinkedList {
public:
    CircularLinkedList();
    ~CircularLinkedList();

    int size() const;             // 获取长度
    bool insert(int pos, int val); // 按位置插入
    bool remove(int pos);         // 按位置删除
    int get(int pos) const;       // 按位置获取
    int find(int val) const;      // 按值查找
    void print() const;           // 打印链表
private:
    CLLNode* head;   // 哨兵节点
    int length;   // 当前有效节点数量（不包括哨兵）
};

#endif //CONTEST_CIRCULARLINKEDLIST_H