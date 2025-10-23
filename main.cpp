#include <iostream>
#include "SeqList.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
using namespace std;

int main() {
    // //顺序表
    // SeqList sl(10);
    //
    // for (int i = 0; i < sizeof(sl)+1; ++i) {
    //     sl.insert(i, i );
    // }
    //
    // printf("SeqList: ");
    // sl.print();
    //
    // //单链表
    // SinglyLinkedList sll;
    // sll.insert(1, 10);
    // sll.insert(2, 20);
    // sll.insert(3, 30);
    //
    // printf("SinglyLinkedList: ");
    // sll.print();

    // //双向链表
    // DoublyLinkedList dll;
    // dll.insert(1, 100);
    // dll.insert(2, 200);
    // dll.insert(3, 300);
    //
    // printf("DoublyLinkedList:");
    // dll.printForward();
    // dll.printBackward();

    //单向环链
    CircularLinkedList cll;
    cll.insert(1, 1000);
    cll.insert(2, 2000);
    cll.insert(3, 3000);
    printf("CircularLinkedList: ");
    cll.print();

    system("pause");

    return 0;
}

