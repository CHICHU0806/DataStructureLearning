cmake_minimum_required(VERSION 3.28)
project(contest)

set(CMAKE_CXX_STANDARD 20)

add_executable(contest main.cpp
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
        Src/SeqStack.h
)

target_include_directories(contest PRIVATE
        Inc
)