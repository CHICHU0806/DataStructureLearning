//
// Created by 20852 on 2025/12/5.
//

#ifndef DATASTRUCTANDALGORITHMLEARING_BINARYTREE_H
#define DATASTRUCTANDALGORITHMLEARING_BINARYTREE_H

#pragma once
#include <iostream>

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();

    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int v) : data(v), left(nullptr), right(nullptr) {}
    };

    // 返回根节点，便于手动构建树
    Node* getRoot() const;

    // 创建根节点
    void setRoot(int value);

    // 插入左右孩子（最原始的二叉树操作）
    Node* insertLeft(Node* parent, int value);
    Node* insertRight(Node* parent, int value);

    // 遍历
    void preOrder(Node* node) const;
    void inOrder(Node* node) const;
    void postOrder(Node* node) const;

    void clear();  // 删除整棵树

private:
    Node* root;

    void destroy(Node* node);
};


#endif //DATASTRUCTANDALGORITHMLEARING_BINARYTREE_H