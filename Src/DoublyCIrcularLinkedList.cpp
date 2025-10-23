//
// Created by 20852 on 2025/10/24.
//

#include "DoublyCIrcularLinkedList.h"

#include <iostream>
#include <stdexcept>

//构造函数
DoublyCircularLinkedList::DoublyCircularLinkedList() {
    head = new DCNode();   // 哨兵节点
    head->next = head;    // next 指向自己
    head->prev = head;    // prev 指向自己
    length = 0;
}

//析构函数
DoublyCircularLinkedList::~DoublyCircularLinkedList() {
    DCNode* current = head->next;
    while (current != head) {
        DCNode* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    delete head;
}

//获取长度
int DoublyCircularLinkedList::size() const {
    return length;
}

//按位置插入
bool DoublyCircularLinkedList::insert(int pos, int value) {
    // 合法位置应为 [1, length+1]
    if (pos < 1 || pos > length + 1) {
        return false;
    }

    auto* newNode = new DCNode(value);
    DCNode* current = head;

    // 遍历到插入位置的前驱节点
    for (int i = 1; i < pos; ++i) {
        current = current->next;
    }

    // 插入新节点
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;

    length++;
    return true;
}

//按位置删除
bool DoublyCircularLinkedList::remove(int pos) {
    if (pos < 1 || pos > length) return false;

    DCNode* toDelete = head->next;
    for (int i = 1; i < pos; ++i) {
        toDelete = toDelete->next;
    }

    // 更新前后节点
    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;

    delete toDelete;
    length--;
    return true;
}

//按位置获取
int DoublyCircularLinkedList::get(int pos) const {
    // 合法位置应为 [1, length]
    if (pos < 1 || pos > length) {
        throw std::out_of_range("Position out of range");
    }
    DCNode* current = head->next;  // 第一个有效节点
    for (int i = 1; i < pos; ++i) {
        current = current->next;
    }
    return current->data;
}

//按值查找
int DoublyCircularLinkedList::find(int value) const {
    DCNode* current = head->next;
    int pos = 1;
    while (current != head) {
        if (current->data == value) {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1; // 未找到
}

//正序打印
void DoublyCircularLinkedList::printForward() const {
    DCNode* current = head->next;
    while (current != head) {
        std::cout << current->data << " ";
        current = current->next;
    }
}

//逆序打印
void DoublyCircularLinkedList::printBackward() const {
    DCNode* current = head->prev;
    while (current != head) {
        std::cout << current->data << " ";
        current = current->prev;
    }
}
