//
// Created by 20852 on 2025/10/23.
//

#include "SinglyLinkedList.h"
#include <iostream>

//构造函数
SinglyLinkedList::SinglyLinkedList() : head(nullptr), length(0) {}

//析构函数
SinglyLinkedList::~SinglyLinkedList() {
    Node* current = head;
    while (current) {
        Node* tmp = current->next;
        delete current;
        current = tmp;
    }
    head = nullptr;
}

//获取长度
int SinglyLinkedList::size() const {
    return length;
}

//按位置插入
bool SinglyLinkedList::insert(int pos, int val) {
    if (pos < 1 || pos > length + 1) {
        return false;
    }

    Node* newNode = new Node(val);
    //第一种情况：插入到头结点前
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
    }
    //第二种情况：插入到非头结点前
    else {
        Node* prev = head;
        for (int i = 1; i < pos - 1; ++i) {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
    length++;
    return true;
}

//按位置删除
bool SinglyLinkedList::remove(int pos) {
    if (pos < 1 || pos > length) {
        return false;
    }
    Node* toDelete;
    //第一种情况：删除头结点
    if (pos == 1) {
        toDelete = head;
        head = head->next;
    }
    //第二种情况：删除非头结点
    else {
        Node* prev = head;
        for (int i = 1; i < pos - 1; ++i) {
            prev = prev->next;
        }
        toDelete = prev->next;
        prev->next = toDelete->next;
    }
    delete toDelete;
    length--;
    return true;
}

//按位置获取
int SinglyLinkedList::get(int pos) const {
    if (pos < 1 || pos > length) {
        throw std::out_of_range("Position out of range");
    }
    Node* current = head;
    for (int i = 1; i < pos; ++i) {
        current = current->next;
    }
    return current->data; // pos == 1
}

//按值查找
int SinglyLinkedList::find(int val) const {
    Node* current = head;
    int pos = 1;
    while (current) {
        if (current->data == val) {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1; // 没找到
}

//打印链表
void SinglyLinkedList::print() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
