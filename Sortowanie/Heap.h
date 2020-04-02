#pragma once
template <typename T>
void Heapify(T* arr, int size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != root) {
        Swap(arr, root, largest);
        Heapify(arr, size, largest);
    }
}
// start - index of arr[] to start sorting
// end - last index of arr[]
template <typename T>
void HeapSort(T* arr, int start, int end) {
    ++end;

    T* temp = new T[end - start];
    for (int i = 0; i < end - start; i++) {
        temp[i] = arr[i + start];
    }

    for (int i = (end - start) / 2 - 1; i >= 0; --i) {
        Heapify(temp, (end - start), i);
    }
    for (int i = (end - start) - 1; i >= 0; --i) {
        Swap(temp, 0, i);
        Heapify(temp, i, 0);
    }

    for (int i = 0; i < end - start; i++) {
        arr[i + start] = temp[i];
    }
    delete[] temp;
}