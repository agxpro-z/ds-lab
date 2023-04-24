#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>

namespace custom {

template<typename T>
class Heap {
  private:
    T* heap;
    bool isMinHeap;
    int capacity;
    int size;

    // Compare elements based on heap type
    bool compare(const T& a, const T& b) {
        if (isMinHeap) {
            return a < b;
        } else {
            return a > b;
        }
    }

    // Heapify
    void heapify(int index) {
        int left = 2 * index + 1; // left child
        int right = 2 * index + 2; // right child
        int smallestOrLargest = index;

        if (left < size && compare(heap[left], heap[smallestOrLargest])) {
            smallestOrLargest = left;
        }

        if (right < size && compare(heap[right], heap[smallestOrLargest])) {
            smallestOrLargest = right;
        }

        if (smallestOrLargest != index) {
            T temp = heap[index];
            heap[index] = heap[smallestOrLargest];
            heap[smallestOrLargest] = temp;
            heapify(smallestOrLargest);
        }
    }

  public:
    // Constructor
    Heap(int capacity, bool isMinHeap) {
        this->heap = new T[capacity];
        this->isMinHeap = isMinHeap;
        this->capacity = capacity;
        this->size = 0;
    }

    // Destructor
    ~Heap() {
        delete[] heap;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void insert(const T& value) {
        if (size == capacity) {
            std::cout << "Heap is full, cannot insert." << std::endl;
            return;
        }

        heap[size] = value;
        int index = size;
        size++;

        while (index > 0) {
            int parent = (index - 1) / 2;

            if (compare(heap[index], heap[parent])) {
                T temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            } else {
                break;
            }
        }
    }

    // Show the top element
    T peek() const {
        if (isEmpty()) {
            std::cout << "Heap is empty, cannot peek." << std::endl;
            return T();
        }

        return heap[0];
    }

    // Remove the top element
    T remove() {
        if (isEmpty()) {
            std::cout << "Heap is empty, cannot extract." << std::endl;
            return T();
        }

        T value = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);

        return value;
    }

    // Show the heap
    void print() const {
        if (isEmpty()) {
            std::cout << "Heap is empty." << std::endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            std::cout << heap[i] << " ";
        }

        std::cout << std::endl;
    }
};

template <typename T>
class HeapSort {
  public:
    // constructor
    HeapSort() {}

    // function to heapify a subtree rooted with node i which is an index in arr[]
    void heapify(T arr[], int n, int i) {
        int largest = i;  // initialize largest as root
        int left = 2 * i + 1;  // left child = 2*i + 1
        int right = 2 * i + 2;  // right child = 2*i + 2

        // if left child is larger than root
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // if right child is larger than largest so far
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // if largest is not root
        if (largest != i) {
            std::swap(arr[i], arr[largest]);

            // recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }

    // main function to do heap sort
    void heapSort(T arr[], int n) {
        // build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; --i) {
            heapify(arr, n, i);
        }

        // one by one extract an element from heap
        for (int i = n - 1; i >= 0; --i) {
            // move current root to end
            std::swap(arr[0], arr[i]);

            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }
};

} // namespace custom

#endif // HEAP_HPP
