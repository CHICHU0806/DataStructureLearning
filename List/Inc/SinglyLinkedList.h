//
// Created by 20852 on 2025/10/23.
//

#ifndef CONTEST_SINGLYLINKEDLIST_H
#define CONTEST_SINGLYLINKEDLIST_H

//单链表
struct Node {
    int data;   //数据
    Node* next; //指向下个节点的指针
    explicit Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
public:
    SinglyLinkedList();           // 构造函数
    ~SinglyLinkedList();          // 析构函数

    int size() const;             // 获取长度
    bool insert(int pos, int val); // 按位置插入
    bool remove(int pos);         // 按位置删除
    int get(int pos) const;       // 按位置获取
    int find(int val) const;      // 按值查找
    void print() const;           // 打印链表

private:
    Node* head;
    int length;
};


#endif //CONTEST_SINGLYLINKEDLIST_H