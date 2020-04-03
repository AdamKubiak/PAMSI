#pragma once
#include "Quick.h"


template <typename T>
void InsertionSort(T* arr, int start, int end) {
    end++;
    int i = start;
    while (i < end) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            Swap(arr, j, j - 1);
            --j;
        }
        ++i;
    }
}