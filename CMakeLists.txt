cmake_minimum_required(VERSION 3.28)
project(DataStructandAlgorithmLearing)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructandAlgorithmLearing main.cpp
        Src/SeqList.cpp
        Inc/SeqList.h
        Src/SinglyLinkedList.cpp
        Inc/SinglyLinkedList.h
        Src/DoublyLinkedList.cpp
        Inc/DoublyLinkedList.h
        Src/CircularLinkedList.cpp
        Inc/CircularLinkedList.h
        Src/DoublyCIrcularLinkedList.cpp
        Inc/DoublyCIrcularLinkedList.h
        Src/StaticLinkedList.cpp
        Inc/StaticLinkedList.h
        Src/SeqStack.cpp
        Inc/SeqStack.h
)

target_include_directories(DataStructandAlgorithmLearing PRIVATE
        Inc
        Src
)