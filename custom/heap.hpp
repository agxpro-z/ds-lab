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

    bool compare(const T& a, const T& b) {
        if (isMinHeap) {
            return a < b;
        } else {
            return a > b;
        }
    }

    void heapify(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
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
    Heap(int capacity, bool isMinHeap) {
        this->heap = new T[capacity];
        this->isMinHeap = isMinHeap;
        this->capacity = capacity;
        this->size = 0;
    }

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

    T peek() const {
        if (isEmpty()) {
            std::cout << "Heap is empty, cannot peek." << std::endl;
            return T();
        }

        return heap[0];
    }

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

} // namespace custom

#endif // HEAP_HPP