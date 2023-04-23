#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>

#include "util.hpp"

namespace custom {

template <typename T>
void insertion_sort(T array[], int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (i < size && j - 1 >= 0 && array[j - 1] > array[j]) {
            swap(array[j - 1], array[j]);
            j--;
        }
    }
}

template <typename T>
void merge(T array[], int start, int mid, int end) {
    int size = (mid - start) + (end - mid);
    T* arr = new T[size];

    int s = start;
    int center = mid;

    int counter = 0;
    while (start < mid && center < end) {
        if (array[start] <= array[center]) {
            arr[counter++] = array[start++];
        } else {
            arr[counter++] = array[center++];
        }
    }

    while (start < mid) {
        arr[counter++] = array[start++];
    }

    while (center < end) {
        arr[counter++] = array[center++];
    }

    for (int i = 0; i < size; i++) {
        array[s++] = arr[i];
    }

    delete[] arr;
}

template <typename T>
void merge_sort(T array[], int start, int end) {
    if (end - start > 1) {
        merge_sort(array, start, (start + end) / 2);
        merge_sort(array, (start + end) / 2, end);
        merge(array, start, (start + end) / 2, end);
    }
}

void count_sort(int array[], int end) {
    int max = max_element<int>(array, 0, end);
    int* count = new int[max + 1]{0};

    for (int i = 0; i < end; i++) {
        count[array[i]]++;
    }

    for (int i = 0, j = 0; i < max + 1; i++) {
        if (count[i] > 0) {
            while (count[i] > 0) {
                array[j++] = i;
                count[i]--;
            }
        }
    }
}

void radix(int array[], int divider, int end) {
    int counter[10] = {0};
    int* r_sorted = new int[end];

    for (int i = 0; i < end; i++) {
        counter[(array[i] / divider) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        counter[i] += counter[i - 1];
    }

    for (int i = end - 1; i >= 0; i--) {
        r_sorted[(counter[(array[i] / divider) % 10]--) - 1] = array[i];
    }

    for (int i = 0; i < end; i++)
        array[i] = r_sorted[i];

    delete[] r_sorted;
}

void radix_sort(int array[], int end) {
    int max = max_element<int>(array, 0, end);
    int e = 1;

    while (max > 0) {
        radix(array, e, end);
        e *= 10;
        max /= 10;
    }
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int left = low;
    int right = high - 1;

    while(left <= right){
        while(array[left] < pivot){
            left++;
        }

        while(array[right] > pivot){
            right--;
        }
 
        if(left < right){
            swap(array[left], array[right]);
        }
    } 
    swap(array[left], array[high]);
    return (left);
}
 
void quick_sort(int array[], int low, int high) {
    if (low < high) {
       int pi = partition(array, low, high);
       quick_sort(array, low, pi - 1);
       quick_sort(array, pi + 1, high);
    }
}

} // namespace custom

#endif // SORT_HPP