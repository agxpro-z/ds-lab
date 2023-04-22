#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <iostream>

#include "node.hpp"

namespace custom {

template<typename T>
class array_deque {
  private:
    int m_size;
    int m_capacity;
    int frontIndex;
    int rearIndex;
    T* m_data;

  public:
    array_deque() : m_size(0), m_capacity(10), frontIndex(-1), rearIndex(-1), m_data(nullptr) {
        m_data = new T[m_capacity];
    }

    array_deque(int cap) : m_size(0), m_capacity(cap), frontIndex(-1), rearIndex(-1), m_data(nullptr) {
        m_data = new T[m_capacity];
    }

    ~array_deque() {
        if (m_data != nullptr)
            delete[] m_data;
    }

    int size() {
        return m_size;
    }

    bool empty() {
        return m_size == 0;
    }

    bool full() {
        return m_size == m_capacity - 1;
    }

    bool push_front(T val) {
        if (!full()) {
            if (m_size == 0) {
                frontIndex = 0;
                rearIndex = 1;
                m_data[frontIndex] = val;
                frontIndex = m_capacity - 1;
            } else {
                if (frontIndex == 0) {
                    frontIndex = m_capacity - 1;
                    m_data[0] = val;
                } else {
                    m_data[frontIndex] = val;
                    frontIndex--;
                }
            }
            m_size++;
            return true;
        }
        return false;
    }


    T pop_front() {
        if (!empty()) {
            if (m_size == 1) {
                T t = m_data[(frontIndex + 1) % m_capacity];
                frontIndex = -1;
                rearIndex = -1;
                m_size--;
                return t;
            } else {
                if (frontIndex == m_capacity - 1) {
                    frontIndex = 0;
                    m_size--;
                    return m_data[m_capacity - 1];
                } else {
                    m_size--;
                    return m_data[++frontIndex];
                }
            }
        } else {
            return T(0);
        }
    }

    bool push_back(T val) {
        if (!full()) {
            if (m_size == 0) {
                frontIndex = m_capacity - 1;
                rearIndex = 0;
                m_data[rearIndex] = val;
                rearIndex++;
            } else {
                if (rearIndex == m_capacity - 1) {
                    rearIndex = 0;
                    m_data[m_capacity - 1] = val;
                } else {
                    m_data[rearIndex] = val;
                    rearIndex++;
                }
            }
            m_size++;
            return true;
        }
        return false;
    }

    T pop_back() {
        if (!empty()) {
            if (m_size == 1) {
                T t = m_data[(rearIndex - 1) % m_capacity];
                frontIndex = -1;
                rearIndex = -1;
                m_size--;
                return t;
            } else {
                if (rearIndex == 0) {
                    rearIndex = m_capacity - 1;
                    m_size--;
                    return m_data[0];
                } else {
                    m_size--;
                    return m_data[--rearIndex];
                }
            }
        } else {
            return T(0);
        }
    }

    T front() {
        return m_data[(frontIndex + 1) % m_capacity];
    }

    T rear() {
        return m_data[(rearIndex - 1) % m_capacity];
    }

    void print() {
        std::cout << frontIndex << " " << rearIndex << " " << m_size << std::endl;
        for (int i = 0; i < m_capacity; i++) {
            std::cout << m_data[i] << " ";
        }

        if (empty()) {
            std::cout << "Deque is empty.\n";
            return;
        }

        std::cout << "Front --> ";
        for (int i = (frontIndex + 1) % m_capacity; i != rearIndex; i = (i + 1) % m_capacity) {
            std::cout << m_data[i] << ' ';
        }
        std::cout << "<-- Rear\n";
    }
};

/*
 * Linked list based Deque
 */
template<typename T>
class linked_list_deque {
  private:
    node<T>* head;
    node<T>* tail;
    int m_size;

  public:
    linked_list_deque() : head(nullptr), tail(nullptr), m_size(0) {}

    ~linked_list_deque() {
        while (head != nullptr) {
            node<T>* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    int size() {
        return m_size;
    }

    bool empty() {
        return m_size == 0;
    }

    bool push_front(T val) {
        if (head == nullptr || tail == nullptr) {
            node<T>* t = new node<T>(val);
            if (t != nullptr) {
                head = tail = t;
                m_size++;
                return true;
            }
            return false;
        }

        node<T>* t = new node<T>(nullptr, val, head);
        if (t == nullptr) {
            return false;
        }
        head->prev = t;
        head = t;
        m_size++;
        return true;
    }

    T pop_front() {
        if (head == nullptr || tail == nullptr) {
            return T(0);
        }

        node<T>* t = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }

        m_size--;
        T tt = t->data;
        delete t;
        return tt;
    }

    bool push_back(T val) {
        if (head == nullptr || tail == nullptr) {
            node<T>* t = new node<T>(val);
            if (t != nullptr) {
                head = tail = t;
                m_size++;
                return true;
            }
            return false;
        }

        node<T>* t = new node<T>(tail, val, nullptr);
        if (t == nullptr) {
            return false;
        }
        tail->next = t;
        tail = t;
        m_size++;
        return true;
    }

    T pop_back() {
        if (head == nullptr || tail == nullptr) {
            return T(0);
        }

        node<T>* t = tail;
        tail = tail->prev;

        if (tail == nullptr) {
            head = nullptr;
        } else {
            tail->next = nullptr;
        }

        m_size--;
        T tt = t->data;
        delete t;
        return tt;
    }

    T front() {
        if (head == nullptr || tail == nullptr) {
            return T(0);
        }
        return head->data;
    }

    T back() {
        if (head == nullptr || tail == nullptr) {
            return T(0);
        }
        return tail->data;
    }

    void print() {
        if (head == nullptr || tail == nullptr) {
            std::cout << "Deque is Empty" << std::endl;
            return;
        }

        node<T>* h = head;
        std::cout << "Front --> ";
        while (h != nullptr) {
            std::cout << h->data << " ";
            h = h->next;
        }
        std::cout << "<-- Rear\n";
    }
};

} // namespace custom

#endif // DEQUE_HPP