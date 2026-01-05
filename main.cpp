#include <iostream>
#include "SeqList.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "DoublyCircularLinkedList.h"
#include "Graph.h"
#include "Heap.h"
#include "Sort/Sort.h"
#include "StaticLinkedList.h"
#include "Stack/Inc/SeqStack.h"
#include "Stack/Inc/LnkStack.h"
#include "Queue/Inc/SeqQueue.h"
#include "Queue/Inc/LinkedQueue.h"
#include "Tree/Inc/BinaryTree.h"
#include "Tree/Inc/BinarySearchTree.h"
#include "Tree/Inc/SeqBinaryTree.h"
#include "queue"
using namespace std;

void print(const vector<int>& a) {
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data = {10, 5, 12, 3, 2, 1, 8, 7, 9, 4};
    vector<int> a;

    a = data;
    Sort::insertionSort(a);
    cout << "Insertion Sort: ";
    print(a);

    a = data;
    Sort::bubbleSort(a);
    cout << "Bubble Sort:    ";
    print(a);

    a = data;
    Sort::selectionSort(a);
    cout << "Selection Sort: ";
    print(a);

    a = data;
    Sort::shellSort(a);
    cout << "Shell Sort:     ";
    print(a);

    return 0;
}