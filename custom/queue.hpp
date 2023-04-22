#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

#include "node.hpp"

namespace custom {
using namespace custom;

template<typename T>
class array_queue {
  private:
    int m_size, m_capacity;
    int frontIndex;
    int rearIndex;
    T* m_data;

  public:
    array_queue() : m_size(0), m_capacity(10), frontIndex(0), rearIndex(0), m_data(nullptr) {
        m_data = new T[m_capacity];
    }

    array_queue(int cap) : m_size(0), m_capacity(cap), frontIndex(0), rearIndex(0), m_data(nullptr) {
        m_data = new T[m_capacity];
    }

    ~array_queue() {
        if (m_data != nullptr)
            delete[] m_data;
    }

    int size() {
        return size;
    }

    bool empty() {
        return m_size == 0;
    }

    bool full() {
        return m_size == m_capacity;
    }

    bool enqueue(T val) {
        if (!full()) {
            if (rearIndex == m_capacity) {
                rearIndex = 0;
            }
            m_data[rearIndex++] = val;
            m_size++;
            // rearIndex++;
            return true;
        }
        return false;
    }

    T dequeue() {
        if (!empty()) {
            if (frontIndex == m_capacity) {
                frontIndex = 0;
            }
            T tmp_val = m_data[frontIndex++];
            m_size--;
            // frontIndex++;
            return tmp_val;
        } else {
            return T(0);
        }
    }


    T front() {
        return m_data[frontIndex % (m_capacity)];
    }

    T back() {
        return m_data[rearIndex - 1];
    }

    void print() {
        if (empty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "Front --> ";

        int f = frontIndex;
        int r = rearIndex;

        do {
            std::cout << m_data[f] << ' ';
            f++;
            if (f > m_capacity) {
                f = 0;
            }
        } while (f != r);
        /*for (int i = (rearIndex) % m_capacity - 1; i >= (frontIndex % (m_capacity - 1)); i--) {
            cout << m_data[i % (m_capacity - 1)] << ' ';
        }*/
        std::cout << "<-- Rear\n";
    }
};

/*
 * Linked list based queue
*/
template<typename T>
class linked_list_queue {
  private:
    node<T>* head;
    node<T>* tail;
    int m_size;

  public:
    linked_list_queue() : head(nullptr), tail(nullptr), m_size(0) {}

    ~linked_list_queue() {
        while (head != nullptr) {
            node<T>* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    int size() {
        return this->m_size;
    }

    bool empty() {
        return this->m_size == 0;
    }

    bool enqueue(T val) {
        if (head == nullptr && tail == nullptr) {
            head = tail = new node<T>(val);
            if (this->head == nullptr || this->tail == nullptr) {
                head = tail = nullptr;
                return false;
            }
            this->m_size++;
            return true;
        }

        node<T>* h = new node<T>(val);
        if (h == nullptr) {
            return false;
        }
        this->m_size++;
        tail->next = h;
        return true;
    }

    T dequeue() {
        if (head == nullptr || tail == nullptr) {
            return T(0);
        };

        if (head == tail) {
            node<T>* tmp = head;
            head = tail = nullptr;
            this->m_size--;
            T t = tmp->val;
            delete tmp;
            return t;
        }

        T t = head->val;
        node<T>* h = head;
        head = head->next;
        this->m_size--;
        delete h;
        return t;
    }

    T front() {
        if (head == nullptr) {
            return T(0);
        }
        return head->data;
    }

    T back() {
        if (tail == nullptr) {
            return T(0);
        }
        return tail->data;
    }

    void print() {
        if (head == nullptr) {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "Front --> ";

        node<T>* h = head;
        while (h!= nullptr) {
            std::cout << h->data << ' ';
            h = h->next;
        }
        std::cout << "<-- Rear\n";
    }
};

} // namespace custom

#endif // QUEUE_HPP
