//
// Created by 20852 on 2025/10/24.
//

#ifndef CONTEST_SEQSTACK_H
#define CONTEST_SEQSTACK_H

/* 顺序栈:(受限制的线性表)
 *后进先出（LIFO）：Last In, First Out
 *只能在一端（栈顶）插入与删除元素
 */
class SeqStack {
public:
    SeqStack(int size = 100); // 构造函数
    ~SeqStack();              // 析构函数

    bool isEmpty() const;     // 判断空
    bool isFull() const;      // 判断满

    bool push(int x);         // 入栈
    bool pop();               // 出栈
    bool topValue(int &x) const;  // 获取栈顶元素

    void clear();             // 清空栈
    void print() const;       // 打印栈内容

private:
    int *data;      // 用来存放栈元素
    int top;        // 栈顶指针
    int maxSize;    // 最大空间
};

#endif //CONTEST_SEQSTACK_H