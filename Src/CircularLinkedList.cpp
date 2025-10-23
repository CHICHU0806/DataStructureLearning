//
// Created by 20852 on 2025/10/24.
//

#include "CircularLinkedList.h"
#include <stdexcept>

//构造函数
CircularLinkedList::CircularLinkedList() {
    head = new CLLNode();  // 创建哨兵节点
    head->next = head;  // 指向自己，形成环
    length = 0;
}

//析构函数
CircularLinkedList::~CircularLinkedList() {
    CLLNode* current = head->next;
    while (current != head) {
        CLLNode* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    delete head;  // 删除哨兵节点
}

//获取长度
int CircularLinkedList::size() const {
    return length;
}

//按位置插入
bool CircularLinkedList::insert(int pos, int value) {
    // 合法位置应为 [1, length+1]
    if (pos < 1 || pos > length + 1) {
        return false;
    }

    CLLNode* newNode = new CLLNode(value);
    CLLNode* current = head;

    // 遍历到插入位置的前驱节点
    for (int i = 1; i < pos; ++i) {
        current = current->next;
    }

    // 插入新节点
    newNode->next = current->next;
    current->next = newNode;

    length++;
    return true;
}

//按位置删除
bool CircularLinkedList::remove(int pos) {
    // 合法位置应为 [1, length]
    if (pos < 1 || pos > length) {
        return false;
    }

    CLLNode* current = head;

    // 遍历到删除位置的前驱节点
    for (int i = 1; i < pos; ++i) {
        current = current->next;
    }

    CLLNode* toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete;

    length--;
    return true;
}

//按位置获取
int CircularLinkedList::get(int pos) const {
    // 合法位置应为 [1, length]
    if (pos < 1 || pos > length) {
        throw std::out_of_range("Position out of range");
    }
    CLLNode* current = head->next;
    for (int i = 1; i < pos; ++i) {
        current = current->next;
    }
    return current->data;
}

//按值查找
int CircularLinkedList::find(int value) const {
    // 遍历链表查找值
    CLLNode* current = head->next;
    int pos = 1;
    while (current != head) {
        if (current->data == value) {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1;  // 未找到
}

// 打印链表
void CircularLinkedList::print() const {
    CLLNode* current = head->next;
    while (current != head) {
        printf("%d ", current->data);
        current = current->next;
    }
}
