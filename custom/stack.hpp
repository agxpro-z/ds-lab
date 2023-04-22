#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "node.hpp"

namespace custom {
using namespace custom;
using namespace std;

/*
 * Stack using array as base.
 */
template<typename T>
class array_stack {
    int m_capacity;
    int m_index;
    T* m_data;

  public:
    array_stack() : m_capacity(10), m_index(-1), m_data(NULL) {
        m_data = new T[m_capacity];
    }

    array_stack(int capacity) : m_capacity(capacity), m_index(-1), m_data(NULL) {
        m_data = new T[m_capacity];
    }

    ~array_stack() {
        if (m_data != NULL)
            delete[] m_data;
    }

    // Methods
    bool empty() {
        return m_index == -1;
    }

    bool full() {
        return m_index == m_capacity - 1;
    }

    int size() {
        return m_index + 1;
    }

    bool push(T value) {
        if (full()) {
            return false;
        } else {
            m_data[++m_index] = value;
            return true;
        }
    }

    void pop() {
        if (!empty()) {
            m_data[m_index--];
        }
    }

    const T& top() {
        if (empty()) {
            T* t = new T();
            return *t;
        } else {
            return m_data[m_index];
        }
    }

    void print() {
        if (empty()) {
            cout << "Stack is empty.\n";
        } else {
            for (int i = m_index; i >= 0; --i) {
                cout << m_data[i];
                if (i == m_index) {
                    cout << " <- top";
                }
                cout << '\n';
            }
        }
    }
};

/*
 * Stack using linked list as base.
 */
template<typename T>
class linked_list_stack {
  private:
    node<T>* head;
    int m_size;

  public:
    // Constructor
    linked_list_stack() : head(nullptr), m_size(0) {}

    // Destructor
    ~linked_list_stack() {
        if (head != nullptr) {
            while (head != nullptr) {
                node<T>* h = head;
                head = head->next;
                delete h;
            }
        }
    }

    // Methods
    bool empty() {
        return m_size == 0 && head == nullptr;
    }

    int size() {
        return this->m_size;
    }

    bool push(T val) {
        if (head == nullptr) {
            node<T>* h = new node<T>(val, nullptr);
            if (h == nullptr) return false;
            head = h;
            return true;
        }

        node<T>* h = new node(val, head);
        if (h == nullptr) return false;
        head = h;
        return true;
    }

    void pop() {
        if (head == nullptr) return;
        node<T>* h = head;
        head = head->next;
        delete h;
    }

    T& top() {
        if (head == nullptr) {
            T* t = new T();
            return *t;
        }
        return head->data;
    }

    void print() {
        if (empty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << head->data << " <- top\n";
            node<T>* h = head->next;
            while (h != nullptr) {
                cout << h->data << endl;
                h = h->next;
            }
        }
    }
};

} // namespace custom

#endif // STACK_HPP