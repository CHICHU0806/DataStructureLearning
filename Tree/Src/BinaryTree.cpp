//
// Created by 20852 on 2025/12/5.
//

#include "BinaryTree.h"

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    clear();
}

BinaryTree::Node* BinaryTree::getRoot() const {
    return root;
}

void BinaryTree::setRoot(int value) {
    clear();
    root = new Node(value);
}

BinaryTree::Node* BinaryTree::insertLeft(Node* parent, int value) {
    if (!parent) return nullptr;
    if (parent->left != nullptr) {
        std::cout << "Left child already exists!" << std::endl;
        return nullptr;
    }
    parent->left = new Node(value);
    return parent->left;
}

BinaryTree::Node* BinaryTree::insertRight(Node* parent, int value) {
    if (!parent) return nullptr;
    if (parent->right != nullptr) {
        std::cout << "Right child already exists!" << std::endl;
        return nullptr;
    }
    parent->right = new Node(value);
    return parent->right;
}

void BinaryTree::preOrder(Node* node) const {
    if (!node) return;
    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void BinaryTree::inOrder(Node* node) const {
    if (!node) return;
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}

void BinaryTree::postOrder(Node* node) const {
    if (!node) return;
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}

void BinaryTree::clear() {
    destroy(root);
    root = nullptr;
}

void BinaryTree::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}
