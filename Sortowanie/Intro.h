#pragma once
#include <math.h>
#include "Insertion.h"
#include "Heap.h"
#include "Quick.h"


template <typename T>
void IntroSortProcedure(T* arr, int start, int end, int maxdepth) {
    int size = end - start + 1;
    if (size <= 16) {
        InsertionSort(arr, start, end);
    }
    else if (maxdepth == 0) {
        HeapSort(arr, start, end);
    }
    else if (start < end) {
        int pivot = Partition(arr, start, end);
        IntroSortProcedure(arr, start, pivot, --maxdepth);
        IntroSortProcedure(arr, pivot + 1, end, --maxdepth);
    }
}

template <typename T>
void IntroSort(T* arr, int start, int end) {
    int maxdepth = (int)log(end - start + 1) * 2;
    IntroSortProcedure(arr, start, end, maxdepth);
}