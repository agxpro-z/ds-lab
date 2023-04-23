#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

#include "node.hpp"

namespace custom {

template<typename T>
class singly_linked_list {
  private:
    node<T>* head;
    node<T>* tail;
    int m_size;

  public:
    singly_linked_list() : m_size(0), head(nullptr), tail(nullptr) {
    }

    bool insert_begin(T val) {
        head = new node<T>(val, head);

        if (tail == nullptr) tail = head;
        if (head != nullptr) {
            m_size++;
            return true;
        }
        else return false;
    }

    bool insert_end(T val) {
        if (tail == nullptr) {
            bool r = insert_begin(val);
            tail = head;
            return r;
        }
        tail->next = new node<T>(val);
        tail = tail->next;
        if (tail != nullptr) {
            m_size++;
            return true;
        }
        else return false;
    }

    T delete_begin() {
        if (head == nullptr) return T(0);
        if (head == tail) tail = head->next;
        T tmp_data = head->data;
        node<T>* n = head;
        head = head->next;
        delete n;
        m_size--;
        return tmp_data;
    }

    T delete_end() {
        if (tail == nullptr) return T(0);
        if (head == tail) {
            T tmp_data = head->data;
            head = tail = head->next;
            m_size--;
            return tmp_data;
        }

        node<T>* th = head;
        node<T>* tt = nullptr;

        while (th->next != nullptr) {
            tt = th;
            th = th->next;
        }
        T tmp_data = th->data;
        tt->next = nullptr;
        tail = tt;
        delete th;
        m_size--;
        return tmp_data;
    }

    int size() {
        return m_size;
    }

    bool empty() {
        return (head == nullptr && tail == nullptr && m_size == 0);
    }

    void print() {
        node<T>* h = head;
        if (h == nullptr) {
            std::cout << "NULL\n";
        } else {
            do {
                std::cout << h->data << " --> ";
                h = h->next;
            } while (h != nullptr);
            std::cout << "NULL\n";
        }
    }
};

template<typename T>
class doubly_linked_list {
  private:
    node<T>* head;
    node<T>* tail;
    int m_size;

  public:
    doubly_linked_list() : m_size(0), head(nullptr), tail(nullptr) {
    }

    bool insert_begin(T val) {
        head = new node<T>(nullptr, val, head);

        if (tail == nullptr) tail = head;
        if (head != nullptr) {
            m_size++;
            return true;
        }
        else return false;
    }

    bool insert_end(T val) {
        if (tail == nullptr) {
            bool r = insert_begin(val);
            return r;
        }
        tail->next = new node<T>(tail, val, nullptr);
        tail = tail->next;
        if (tail != nullptr) {
            m_size++;
            return true;
        }
        else return false;
    }

    T delete_begin() {
        if (head == nullptr) return T(0);
        if (head == tail) {
            T tmp_data = head->data;
            head = tail = nullptr;
            m_size--;
            return tmp_data;
        }

        T tmp_data = head->data;
        node<T>* n = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete n;
        m_size--;
        return tmp_data;
    }

    T delete_end() {
        if (tail == nullptr) return T(0);
        if (head == tail) {
            return delete_begin();
        }

        node<T>* th = head;
        node<T>* tt = nullptr;

        while (th->next != nullptr) {
            tt = th;
            th = th->next;
        }
        T tmp_data = th->data;
        tt->next = nullptr;
        tail = tt;
        delete th;
        m_size--;
        return tmp_data;
    }

    int size() {
        return m_size;
    }

    bool empty() {
        return (head == nullptr && tail == nullptr && m_size == 0);
    }

    void print() {
        node<T>* h = head;
        if (h == nullptr) {
            std::cout << "NULL\n";
        } else {
            std::cout << "NULL <--> ";
            do {
                std::cout << h->data << " <--> ";
                h = h->next;
            } while (h != nullptr);
            std::cout << "NULL\n";
        }
    }
};

template<typename T>
class circular_singly_linked_list {
  private:
    node<T>* head;
    node<T>* tail;
    int m_size;

  public:
    circular_singly_linked_list() : m_size(0), head(nullptr), tail(nullptr) {
    }

    bool insert_begin(T val) {
        head = new node<T>(val, head);

        if (tail == nullptr) tail = head;
        tail->next = head;

        if (head != nullptr) {
            m_size++;
            return true;
        } else
            return false;
    }

    bool insert_end(T val) {
        if (tail == nullptr) {
            bool r = insert_begin(val);
            return r;
        }
        tail->next = new node<T>(val, head);
        tail = tail->next;
        if (tail != nullptr) {
            m_size++;
            return true;
        } else
            return false;
    }

    T delete_begin() {
        if (head == nullptr && head == nullptr) return T(0);
        if (head == tail) {
            tail = head->next = nullptr;
            T tmp_data = head->data;
            node<T>* n = head;
            delete n;
            head = nullptr;
            m_size--;
            return tmp_data;
        }
        T tmp_data = head->data;
        node<T>* n = head;
        head = head->next;
        tail->next = head;
        delete n;
        m_size--;
        return tmp_data;
    }

    T delete_end() {
        if (tail == nullptr && head == nullptr) return T(0);
        if (head == tail) {
            return delete_begin();
        }

        node<T>* th = head;
        node<T>* tt = nullptr;

        while (th->next != head) {
            tt = th;
            th = th->next;
        }
        T tmp_data = th->data;
        tt->next = head;
        tail = tt;
        delete th;
        m_size--;
        return tmp_data;
    }

    int size() {
        return m_size;
    }

    bool empty() {
        return (head == nullptr && tail == nullptr && m_size == 0);
    }

    void print() {
        node<T>* h = head;
        if (h == nullptr) {
            std::cout << "NULL\n";
        } else {
            do {
                std::cout << h->data << " --> ";
                h = h->next;
            } while (h != head);
            std::cout << head->data << "\n";
        }
    }

    void printc() {
        node<T>* h = head;
        if (h == nullptr) {
            std::cout << "NULL\n";
        } else {
            int count = 0;
            do {
                std::cout << h->data;
                count += std::to_string(h->data).length();
                if (h->next != head) {
                    std::cout << " --> ";
                    count += 5;
                }
                h = h->next;
            } while (h != head);
            std::cout << " -";

            std::cout << "\n^";
            for (int i = 0; i < count; i++) {
                std::cout << " ";
            }
            std::cout << "|\n|";
            for (int i = 0; i < count; i++) {
                std::cout << "_";
            }
            std::cout << "|" << std::endl;
        }
    }
};

template<typename T>
class circular_doubly_linked_list {
  private:
    node<T>* head;
    int m_size;

  public:
    circular_doubly_linked_list() : m_size(0), head(nullptr) {
    }

    bool insert_begin(T val) {
        if (head == nullptr) {
            head = new node<T>(val);
            if (head == nullptr) {
                return false;
            }
            head->next = head->prev = head;
        } else {
            node<T>* h = new node<T>(head->prev, val, head);
            if (h == nullptr)
                return false;

            head->prev->next = h;
            head->prev = h;
            head = h;
        }
        m_size++;
        return true;
    }

    bool insert_end(T val) {
        if (head == nullptr) {
            head = new node<T>(val);
            if (head == nullptr) {
                return false;
            }
            head->next = head->prev = head;
        } else {
            node<T>* h = new node<T>(head->prev, val, head);
            if (h == nullptr)
                return false;

            head->prev->next = h;
            head->prev = h;
        }
        m_size++;
        return true;
    }

    T delete_begin() {
        if (head == nullptr) return T(0);

        if (size() == 1) {
            T t = head->data;
            delete head;
            head = nullptr;
            return t;
        }

        T tmp_data = head->data;
        node<T>* n = head;
        head = head->next;
        head->prev = n->prev;
        head->prev->next = head;

        delete n;
        m_size--;
        return tmp_data;
    }

    T delete_end() {
        if (head == nullptr) return T(0);

        if (size() == 1) {
            T t = head->data;
            delete head;
            head = nullptr;
            return t;
        }

        T tmp_data = head->prev->data;
        node<T>* n = head->prev;

        head->prev = n->prev;
        head->prev->next = head;
        delete n;
        m_size--;
        return tmp_data;
    }

    int size() {
        return m_size;
    }

    bool empty() {
        return (head == nullptr && m_size == 0);
    }

    void print() {
        node<T>* h = head;
        if (h == nullptr) {
            std::cout << "NULL\n";
        } else {
            do {
                std::cout << h->data << " <--> ";
                h = h->next;
            } while (h != head);
            std::cout << head->data << "\n";
        }
    }

    void printc() {
        node<T>* h = head;
        if (h == nullptr) {
            std::cout << "NULL\n";
        } else {
            int count = 0;
            do {
                std::cout << h->data;
                count += std::to_string(h->data).length();
                if (h->next != head) {
                    std::cout << " <--> ";
                    count += 6;
                }
                h = h->next;
            } while (h != head);
            std::cout << " <-";

            std::cout << "\n^";
            for (int i = 0; i <= count; i++) {
                std::cout << " ";
            }
            std::cout << "|\n|";
            for (int i = 0; i <= count; i++) {
                std::cout << "_";
            }
            std::cout << "|" << std::endl;
        }
    }
};

} // namespace custom

#endif // LINKED_LIST_HPP
