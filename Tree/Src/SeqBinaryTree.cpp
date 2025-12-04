//
// Created by 20852 on 2025/12/5.
//

#include "SeqBinaryTree.h"
#include <iostream>

SeqBinaryTree::SeqBinaryTree(int cap) : capacity(cap) {
    data.reserve(capacity); // 提前分配空间
}

bool SeqBinaryTree::isEmpty() const {
    return data.empty();
}

// 层次插入（数组尾部插入）
bool SeqBinaryTree::insert(int value) {
    if (data.size() >= capacity) {
        std::cout << "Tree is full, insert failed." << std::endl;
        return false;
    }
    data.push_back(value);
    return true;
}

int SeqBinaryTree::getRoot() const {
    if (isEmpty()) throw std::runtime_error("Tree is empty");
    return data[0];
}

int SeqBinaryTree::getLeftChild(int index) const {
    int left = 2 * index + 1;
    if (left >= data.size()) throw std::runtime_error("No left child");
    return data[left];
}

int SeqBinaryTree::getRightChild(int index) const {
    int right = 2 * index + 2;
    if (right >= data.size()) throw std::runtime_error("No right child");
    return data[right];
}

// ---------- 遍历 ----------

void SeqBinaryTree::preOrder() const {
    preOrder(0);
    std::cout << std::endl;
}

void SeqBinaryTree::inOrder() const {
    inOrder(0);
    std::cout << std::endl;
}

void SeqBinaryTree::postOrder() const {
    postOrder(0);
    std::cout << std::endl;
}

// 层序遍历直接按数组顺序输出
void SeqBinaryTree::levelOrder() const {
    for (int val : data) std::cout << val << " ";
    std::cout << std::endl;
}

// ---------- 私有递归实现 ----------

void SeqBinaryTree::preOrder(int index) const {
    if (index >= data.size()) return;
    std::cout << data[index] << " ";
    preOrder(2 * index + 1);
    preOrder(2 * index + 2);
}

void SeqBinaryTree::inOrder(int index) const {
    if (index >= data.size()) return;
    inOrder(2 * index + 1);
    std::cout << data[index] << " ";
    inOrder(2 * index + 2);
}

void SeqBinaryTree::postOrder(int index) const {
    if (index >= data.size()) return;
    postOrder(2 * index + 1);
    postOrder(2 * index + 2);
    std::cout << data[index] << " ";
}
