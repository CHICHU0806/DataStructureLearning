//
// Created by 20852 on 2025/10/23.
//

#include "../Inc/SeqList.h"
#include <iostream>

//构造函数
SeqList::SeqList(int cap) : capacity(cap), length(0) {
    if (capacity <= 0) {
        capacity = 10;
    }
    data = new int[capacity];
}

//析构函数
SeqList::~SeqList() {
    delete[] data;
    data = nullptr;
}

//插入
bool SeqList::insert(int pos, int value) {
    if (pos < 1 || pos > length + 1 || length >= capacity) {
        return false; // 插入位置不合法或顺序表已满
    }
    for (int i = length; i > pos; --i) {
        data[i] = data[i - 1]; // 元素后移
    }
    data[pos-1] = value;
    length++;
    return true;
}

//删除
bool SeqList::remove(int pos) {
    if (pos < 1 || pos > length) {
        return false;
    }
    for (int i = pos; i < length; ++i) {
        data[i-1] = data[i]; // 元素前移
    }
    length--;
    return true;
}

//获取元素
int SeqList::get(int pos) {
    if (pos < 1 || pos > length) {
        throw std::out_of_range("Position out of range");
    }
    return data[pos-1];
}

//按值查找
int SeqList::find(int value) {
    for (int i = 0; i < length; ++i) {
        if (data[i] == value) {
            return i + 1; // 返回位置
        }
    }
    return -1; // 未找到
}

//打印
void SeqList::print() {
    for (int i = 0; i < length; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
