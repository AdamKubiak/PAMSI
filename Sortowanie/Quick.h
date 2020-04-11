#pragma once

template <typename T>
void Swap(T* arr, int s1, int s2) {
    T x = arr[s1];
    arr[s1] = arr[s2];
    arr[s2] = x;
}

template <typename T>
int Partition(T* arr, int start, int end) {
    T pivot = arr[(end + start) / 2];
    int i = start - 1;
    int j = end + 1;
    while (1) {
        do {
            ++i;
        } while (arr[i] < pivot);

        do {
            --j;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }
        Swap(arr, i, j);
    }
}


template <typename T>
void quickSort(T* arr, int start, int end) {
    if (start < end) {
        int pivot = Partition(arr, start, end);
        quickSort(arr, start, pivot);
        quickSort(arr, pivot + 1, end);
    }
}

template <typename T>
int ReversePartition(T* arr, int start, int end) {
    T pivot = arr[(end + start) / 2];
    int i = start - 1;
    int j = end + 1;
    while (1) {
        do {
            ++i;
        } while (arr[i] > pivot);

        do {
            --j;
        } while (arr[j] < pivot);

        if (i >= j) {
            return j;
        }
        Swap(arr, i, j);
    }
}

template <typename T>
void ReverseQuickSort(T* arr, int start, int end) {
    if (start < end) {
        int pivot = ReversePartition(arr, start, end);
        ReverseQuickSort(arr, start, pivot);
        ReverseQuickSort(arr, pivot + 1, end);
    }
}