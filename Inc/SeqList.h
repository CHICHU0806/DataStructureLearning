//
// Created by 20852 on 2025/10/23.
//

#ifndef CONTEST_SEQLIST_H
#define CONTEST_SEQLIST_H

class SeqList {
public:
    explicit SeqList(int cap = 10);  // 构造函数，初始化容量，默认为10
    ~SeqList();             // 析构函数，释放内存

    bool insert(int pos, int value); // 插入
    bool remove(int pos);            // 删除
    int get(int pos);                // 获取元素
    int find(int value);             // 按值查找
    void print();                    // 打印

private:
    int* data;      // 指向动态数组
    int length;     // 当前顺序表长度
    int capacity;   // 最大容量
};

#endif //CONTEST_SEQLIST_H