//
// Created by 20852 on 2025/10/24.
//

#ifndef CONTEST_STATICLINKEDLIST_H
#define CONTEST_STATICLINKEDLIST_H

// 静态链表
struct StaticNode {
    int data;  // 数据域
    int next;  // 指针域（存储下一个元素的下标）
};

class StaticLinkedList {
public:
    StaticLinkedList();   // 构造函数
    bool insert(int pos, int value); // 插入
    bool remove(int pos);            // 删除
    int get(int pos) const;          // 获取数据
    int find(int value) const;       // 查找
    void print() const;              // 打印
private:
    static const int MAX_SIZE = 100;  // 最大容量
    StaticNode nodes[MAX_SIZE] = {};       // 节点数组
    int head;     // 头节点下标
    int free;     // 空闲链表的头下标（管理空位置）
    int length;   // 当前链表长度
};

#endif //CONTEST_STATICLINKEDLIST_H