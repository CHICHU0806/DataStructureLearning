//
// Created by 20852 on 2025/10/24.
//

#include "StaticLinkedList.h"
#include <iostream>
#include <stdexcept>

// 构造函数
StaticLinkedList::StaticLinkedList() {
    head = -1;  // 初始化头节点为 -1，表示空链表
    length = 0;

    // 初始化空闲链表
    for (int i = 0; i < MAX_SIZE - 1; ++i) {
        nodes[i].next = i + 1;
    }
    nodes[MAX_SIZE - 1].next = -1; // 最后一个节点的 next 指向 -1
    free = 0; // 空闲链表头指向第一个节点
}

// 插入
bool StaticLinkedList::insert(int pos, int value) {
    // 位置合法 + 有空闲节点
    if (pos < 1 || pos > length + 1 || free == -1) {
        return false;
    }

    // 从空闲链表中取出一个节点
    int newIndex = free;           // 当前空闲位置
    free = nodes[free].next;       // 空闲链表指向下一个空位
    nodes[newIndex].data = value;

    // 插入到第一个位置（头插入）
    if (pos == 1) {
        nodes[newIndex].next = head;
        head = newIndex;
    }
    // 插入到其他位置
    else {
        int prev = head;
        // 找到第 pos-1 个节点（插入位置的前驱）
        for (int i = 1; i < pos - 1; ++i) {
            prev = nodes[prev].next;
        }

        // 链接新节点
        nodes[newIndex].next = nodes[prev].next;
        nodes[prev].next = newIndex;
    }

    length++;
    return true;
}

//删除
bool StaticLinkedList::remove(int pos) {
    // 位置合法
    if (pos < 1 || pos > length) {
        return false;
    }

    int toDelete;
    // 删除第一个节点
    if (pos == 1) {
        toDelete = head;
        head = nodes[head].next;
    }
    // 删除其他位置节点
    else {
        int prev = head;
        // 找到第 pos-1 个节点（删除位置的前驱）
        for (int i = 1; i < pos - 1; ++i) {
            prev = nodes[prev].next;
        }
        toDelete = nodes[prev].next;
        nodes[prev].next = nodes[toDelete].next;
    }

    // 回收节点到空闲链表
    nodes[toDelete].next = free;
    free = toDelete;

    length--;
    return true;
}

// 获取数据
int StaticLinkedList::get(int pos) const {
    // 位置合法
    if (pos < 1 || pos > length) {
        throw std::out_of_range("Position out of range");
    }
    int current = head;
    for (int i = 1; i < pos; ++i) {
        current = nodes[current].next;
    }
    return nodes[current].data;
}

// 查找
int StaticLinkedList::find(int value) const {
    int current = head;
    int pos = 1;
    while (current != -1) {
        if (nodes[current].data == value) {
            return pos;
        }
        current = nodes[current].next;
        pos++;
    }
    return -1; // 未找到
}

// 打印
void StaticLinkedList::print() const {
    int current = head;
    while (current != -1) {
        std::cout << nodes[current].data << " ";
        current = nodes[current].next;
    }
    std::cout << std::endl;
}
