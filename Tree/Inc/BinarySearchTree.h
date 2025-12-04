//
// Created by 20852 on 2025/12/5.
//

#ifndef DATASTRUCTANDALGORITHMLEARING_BINARYSEARCHTREE_H
#define DATASTRUCTANDALGORITHMLEARING_BINARYSEARCHTREE_H

class BST {
public:
    BST();
    ~BST();

    bool insert(int value);
    bool search(int value) const;
    void inOrder() const;
    void preOrder() const;
    void postOrder() const;
    void clear();

private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int v) : data(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // 私有递归函数
    bool _insert(Node*& node, int value);
    bool _search(Node* node, int value) const;
    void _inOrder(Node* node) const;
    void _preOrder(Node* node) const;
    void _postOrder(Node* node) const;
    void _clear(Node* node);
};


#endif //DATASTRUCTANDALGORITHMLEARING_BINARYSEARCHTREE_H