cmake_minimum_required(VERSION 3.28)
project(DataStructandAlgorithmLearing)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructandAlgorithmLearing main.cpp
        List/Src/SeqList.cpp
        List/Inc/SeqList.h
        List/Src/SinglyLinkedList.cpp
        List/Inc/SinglyLinkedList.h
        List/Src/DoublyLinkedList.cpp
        List/Inc/DoublyLinkedList.h
        List/Src/CircularLinkedList.cpp
        List/Inc/CircularLinkedList.h
        List/Src/DoublyCIrcularLinkedList.cpp
        List/Inc/DoublyCIrcularLinkedList.h
        List/Src/StaticLinkedList.cpp
        List/Inc/StaticLinkedList.h
        Stack/Src/SeqStack.cpp
        Stack/Inc/SeqStack.h
        Stack/Src/LnkStack.cpp
        Stack/Inc/LnkStack.h
        Queue/Src/LinkedQueue.cpp
        Queue/Inc/LinkedQueue.h
        Queue/Src/SeqQueue.cpp
        Queue/Inc/SeqQueue.h
        Tree/Src/BinaryTree.cpp
        Tree/Inc/BinaryTree.h
        Tree/Src/SeqBinaryTree.cpp
        Tree/Inc/SeqBinaryTree.h
        Tree/Src/BinarySearchTree.cpp
        Tree/Inc/BinarySearchTree.h
        Graph/Src/Graph.cpp
        Graph/Inc/Graph.h
)

target_include_directories(DataStructandAlgorithmLearing PRIVATE
        List/Inc
        Stack/Inc
        Queue/Inc
        Tree/Inc
        Graph/Inc
)