#ifndef DATASTRUCTANDALGORITHMLEARING_SORT_H
#define DATASTRUCTANDALGORITHMLEARING_SORT_H

#include <vector>

class Sort {
public:
    static void insertionSort(std::vector<int>& a);
    static void bubbleSort(std::vector<int>& a);
    static void selectionSort(std::vector<int>& a);
    static void shellSort(std::vector<int>& a);
};

#endif
