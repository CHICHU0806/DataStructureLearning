#include <iostream>
#include "SeqList.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "DoublyCircularLinkedList.h"
#include "StaticLinkedList.h"
#include "Stack/Inc/SeqStack.h"
#include "Stack/Inc/LnkStack.h"
#include "Queue/Inc/SeqQueue.h"
#include "Queue/Inc/LinkedQueue.h"
#include "Tree/Inc/BinaryTree.h"
#include "Tree/Inc/BinarySearchTree.h"
#include "Tree/Inc/SeqBinaryTree.h"
using namespace std;

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    cout << "In-order Traversal of BST: ";
    bst.postOrder(); // Expected output: 20 30 40 50 60 70 80
    cout << endl;
    return 0;
}