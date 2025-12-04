//
// Created by 20852 on 2025/12/5.
//

#ifndef DATASTRUCTANDALGORITHMLEARING_SEQBINARYTREE_H
#define DATASTRUCTANDALGORITHMLEARING_SEQBINARYTREE_H

#include <vector>

class SeqBinaryTree {
public:
    SeqBinaryTree(int capacity = 100);  // 构造函数
    ~SeqBinaryTree() = default;

    bool insert(int value);              // 层次插入
    int getRoot() const;                 // 获取根节点
    int getLeftChild(int index) const;   // 获取左孩子
    int getRightChild(int index) const;  // 获取右孩子

    void preOrder() const;               // 前序遍历
    void inOrder() const;                // 中序遍历
    void postOrder() const;              // 后序遍历
    void levelOrder() const;             // 层序遍历

    bool isEmpty() const;

private:
    std::vector<int> data;               // 存储节点
    int capacity;                        // 最大容量

    void preOrder(int index) const;
    void inOrder(int index) const;
    void postOrder(int index) const;
};

#endif //DATASTRUCTANDALGORITHMLEARING_SEQBINARYTREE_H