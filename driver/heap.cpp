#include <iostream>

#include "../custom/heap.hpp"
#include "heap.hpp"

using namespace custom;
using namespace std;

void max_heap_menu() {
    std::cout << "\n\tMax Heap\n";
    std::cout << "1. Insert\n";
    std::cout << "2. Peek\n";
    std::cout << "3. Remove\n";
    std::cout << "4. Print Heap\n";
    std::cout << "0. Exit\n";
    std::cout << " :> ";
}

void max_heap_driver() {
    cout << "Enter heap capacity: ";
    int in;
    cin >> in;

    Heap<int> heap(in, false);

    do {
        max_heap_menu();
        std::cin >> in;

        switch(in) {
            case 1:
                std::cout << "Enter an integer: ";
                int x;
                std::cin >> x;
                heap.insert(x);
                break;
            case 2:
                std::cout << "Top element: " << heap.peek() << std::endl;
                break;
            case 3:
                std::cout << "Removed: " << heap.remove() << std::endl;
                break;
            case 4:
                heap.print();
                break;
        }
    } while (in != 0);
}


void min_heap_menu() {
    std::cout << "\n\tMin Heap\n";
    std::cout << "1. Insert\n";
    std::cout << "2. Peek\n";
    std::cout << "3. Remove\n";
    std::cout << "4. Print Heap\n";
    std::cout << "0. Exit\n";
    std::cout << " :> ";
}

void min_heap_driver() {
    cout << "Enter heap capacity: ";
    int in;
    cin >> in;

    Heap<int> heap(in, true);

    do {
        min_heap_menu();
        std::cin >> in;

        switch(in) {
            case 1:
                std::cout << "Enter an integer: ";
                int x;
                std::cin >> x;
                heap.insert(x);
                break;
            case 2:
                std::cout << "Top element: " << heap.peek() << std::endl;
                break;
            case 3:
                std::cout << "Removed: " << heap.remove() << std::endl;
                break;
            case 4:
                heap.print();
                break;
        }
    } while (in != 0);
}

void heap_sort_driver() {
    cout << "Heap sort\n";
    cout << "Enter no. of elements: ";
    int n;
    cin >> n;

    // Take input in the array
    cout << "Enter elements: ";
    int* elements = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    HeapSort<int> heapSort;
    heapSort.heapSort(elements, n);

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
    delete[] elements;
}
