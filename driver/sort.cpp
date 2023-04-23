#include <iostream>

#include "../custom/sort.hpp"
#include "sort.hpp"

using namespace custom;
using namespace std;

void insertion_sort_driver() {
    cout << "Insertion sort\n";
    cout << "Enter no. of elements: ";
    int n;
    cin >> n;

    cout << "Enter elements: ";
    int* elements = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }
    insertion_sort<int>(elements, n);

    for (int i = 0; i < n; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
    delete[] elements;
}

void merge_sort_driver() {
    cout << "Merge sort\n";
    cout << "Enter no. of elements: ";
    int n;
    cin >> n;

    cout << "Enter elements: ";
    int* elements = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }
    merge_sort<int>(elements, 0, n);

    for (int i = 0; i < n; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
    delete[] elements;
}

void quick_sort_driver() {
    cout << "Quick sort\n";
    cout << "Enter no. of elements: ";
    int n;
    cin >> n;

    cout << "Enter elements: ";
    int* elements = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }
    quick_sort(elements, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
    delete[] elements;
}

void count_sort_driver() {
    cout << "Count sort\n";
    cout << "Enter no. of elements: ";
    int n;
    cin >> n;

    cout << "Enter elements: ";
    int* elements = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }
    count_sort(elements, n);

    for (int i = 0; i < n; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
    delete[] elements;
}

void radix_sort_driver() {
    cout << "Radix sort\n";
    cout << "Enter no. of elements: ";
    int n;
    cin >> n;

    cout << "Enter elements: ";
    int* elements = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }
    radix_sort(elements, n);

    for (int i = 0; i < n; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
    delete[] elements;
}
