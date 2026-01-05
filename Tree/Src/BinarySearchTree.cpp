 //
// Created by 20852 on 2025/12/5.
//

#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear();
}

bool BST::insert(int value) {
    return _insert(root, value);
}

bool BST::_insert(Node*& node, int value) {
    if (node == nullptr) {
        node = new Node(value);
        return true;
    }
    if (value < node->data) return _insert(node->left, value);
    else if (value > node->data) return _insert(node->right, value);
    else return false;
}

bool BST::search(int value) const {
    return _search(root, value);
}

bool BST::_search(Node* node, int value) const {
    if (!node) return false;
    if (value == node->data) return true;
    else if (value < node->data) return _search(node->left, value);
    else return _search(node->right, value);
}

void BST::inOrder() const {
    _inOrder(root);
    cout << endl;
}

void BST::preOrder() const {
    _preOrder(root);
    cout << endl;
}

void BST::postOrder() const {
    _postOrder(root);
    cout << endl;
}

void BST::_inOrder(Node* node) const {
    if (!node) return;
    _inOrder(node->left);
    cout << node->data << " ";
    _inOrder(node->right);
}

void BST::_preOrder(Node* node) const {
    if (!node) return;
    cout << node->data << " ";
    _preOrder(node->left);
    _preOrder(node->right);
}

void BST::_postOrder(Node* node) const {
    if (!node) return;
    _postOrder(node->left);
    _postOrder(node->right);
    cout << node->data << " ";
}

void BST::clear() {
    _clear(root);
    root = nullptr;
}

void BST::_clear(Node* node) {
    if (!node) return;
    _clear(node->left);
    _clear(node->right);
    delete node;
}

int BST::smallCount(int K) const {
    return _smallCount(root, K);
}

int BST::_smallCount(Node* node, int K) const {
    if (node == nullptr) {
        return 0;
    }

    if (node->data > K) {
        return _smallCount(node->left, K);
    } else {
        return 1
             + _smallCount(node->left, K)
             + _smallCount(node->right, K);
    }
}
