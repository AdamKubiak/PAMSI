#pragma once

template <typename T>
void Merge(T* arr, int start, int middle, int end) {
    T* temp = new T[end - start + 1];
    int k = 0, i = start, j = middle + 1;

    while (i <= middle && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            ++i;
        }
        else {
            temp[k] = arr[j];
            ++j;
        }
        ++k;
    }
    while (i <= middle) {
        temp[k] = arr[i];
        ++i;
        ++k;
    }
    while (j <= end) {
        temp[k] = arr[j];
        ++j;
        ++k;
    }
    for (i = start; i <= end; i++) {
        arr[i] = temp[i - start];
    }
    delete[] temp;
}



template <typename T>
void MergeSort(T* arr, int start, int end) {
    if (start < end) {
        int middle = start + (end - start) / 2;
        MergeSort(arr, start, middle);
        MergeSort(arr, middle + 1, end);
        Merge(arr, start, middle, end);
    }
}