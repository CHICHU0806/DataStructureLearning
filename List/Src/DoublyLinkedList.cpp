//
// Created by 20852 on 2025/10/23.
//

#include "../Inc/DoublyLinkedList.h"

#include <stdexcept>

//构造函数
DoublyLinkedList::DoublyLinkedList() {
    head = new DNode(0); // 哨兵节点
    tail = new DNode(0); // 哨兵节点
    head->next = tail;
    tail->prev = head;
    length = 0;
}

//析构函数
DoublyLinkedList::~DoublyLinkedList() {
    DNode* current = head;
    while (current) {
        DNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

//获取链表长度
int DoublyLinkedList::size() const {
    return length;
}

//按位置插入
bool DoublyLinkedList::insert(int pos, int value) {
    // 合法位置应为 [1, length+1]
    if (pos < 1 || pos > length + 1) {
        return false;
    }

    auto* newNode = new DNode(value);
    DNode* current = head;  // head 是哨兵节点

    // 统一遍历到插入位置的前驱节点（不需要特殊判断 pos==1）
    for (int i = 1; i < pos; ++i) {
        current = current->next;
    }

    // 完成插入
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != nullptr) {
        current->next->prev = newNode;  // 修复后继节点的 prev
    } else {
        tail = newNode; // 尾插的情况
    }
    current->next = newNode;

    length++;
    return true;
}

//按位置删除
bool DoublyLinkedList::remove(int pos) {
    // 合法位置应为 [1, length]
    if (pos < 1 || pos > length) {
        return false;
    }

    DNode* current = head;  // head 是哨兵节点

    // 统一遍历到删除位置的前驱节点（不需要特殊判断 pos==1）
    for (int i = 1; i < pos; ++i) {
        current = current->next;
    }

    DNode* toDelete = current->next;
    current->next = toDelete->next;
    if (toDelete->next != nullptr) {
        toDelete->next->prev = current;  // 修复后继节点的 prev
    } else {
        tail = current; // 删除尾节点的情况
    }
    delete toDelete;

    length--;
    return true;
}

//按位置读取
int DoublyLinkedList::get(int pos) const {
    // 合法位置应为 [1, length]
    if (pos < 1 || pos > length) {
        throw std::out_of_range("Position out of range");
    }
    DNode* current = head->next;  // 第一个有效节点
    for (int i = 1; i < pos; ++i) {
        current = current->next;
    }
    return current->data;
}

//按值查找
int DoublyLinkedList::find(int value) const {
    DNode* current = head->next;  // 第一个有效节点
    int pos = 1;
    while (current != tail) {
        if (current->data == value) {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1; // 未找到
}

//正序打印
void DoublyLinkedList::printForward() const {
    DNode* current = head->next;  // 第一个有效节点
    while (current != tail) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

//逆序打印
void DoublyLinkedList::printBackward() const {
    DNode* current = tail->prev;  // 最后一个有效节点
    while (current != head) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}