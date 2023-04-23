#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>

namespace custom {

#include <iostream>

template<typename T>
class HashTable {
  private:
    int size;
    T *table;

  public:
    HashTable(int size) {
        this->size = size;
        table = new T[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1;
        }
    }

    ~HashTable() {
        delete[] table;
    }

    int hashFunction(T key) {
        return key % size;
    }

    int linearProbing(int key, int index) {
        int i = 0;
        while (table[(index + i) % size] != -1 && table[(index + i) % size] != key) {
            i++;
        }
        return (index + i) % size;
    }

    void insert(T key) {
        int index = hashFunction(key);
        if (table[index] == -1) {
            table[index] = key;
        } else {
            index = linearProbing(key, index);
            table[index] = key;
        }
    }

    void remove(T key) {
        int index = hashFunction(key);
        if (table[index] == key) {
            table[index] = -1;
        } else {
            int tempIndex = index;
            index = linearProbing(key, index);
            if (table[index] == key) {
                table[index] = -1;
            } else {
                std::cout << "Key not found" << std::endl;
                return;
            }
        }
        std::cout << "Key deleted\n";
    }

    bool search(T key) {
        int index = hashFunction(key);
        if (table[index] == key) {
            return true;
        } else {
            int tempIndex = index;
            index = linearProbing(key, index);
            if (table[index] == key) {
                return true;
            } else {
                return false;
            }
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << "Index " << i << ": ";
            if (table[i] == -1) {
                std::cout << "Empty" << std::endl;
            } else {
                std::cout << table[i] << std::endl;
            }
        }
    }
};

const int TABLE_SIZE = 10;

template <typename T>
class HashNode {
public:
    T value;
    HashNode<T>* next;

    HashNode(const T& val) : value(val), next(nullptr) {}
};

template <typename T>
class HashTableSC {
  private:
    HashNode<T>* table[TABLE_SIZE];

  public:
    HashTableSC() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = nullptr;
    }

    ~HashTableSC() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            HashNode<T>* current = table[i];
            while (current != nullptr) {
                HashNode<T>* prev = current;
                current = current->next;
                delete prev;
            }
            table[i] = nullptr;
        }
    }

    int hashFunction(const T& key) const {
        return key % TABLE_SIZE;
    }

    void insert(const T& key) {
        int index = hashFunction(key);
        HashNode<T>* newNode = new HashNode<T>(key);

        if (table[index] == nullptr) {
            table[index] = newNode;
        }
        else {
            HashNode<T>* current = table[index];
            while (current->next != nullptr)
                current = current->next;
            current->next = newNode;
        }
    }

    bool search(const T& key) const {
        int index = hashFunction(key);
        HashNode<T>* current = table[index];

        while (current != nullptr) {
            if (current->value == key)
                return true;
            current = current->next;
        }

        return false;
    }

    bool remove(const T& key) {
        int index = hashFunction(key);
        HashNode<T>* current = table[index];
        HashNode<T>* prev = nullptr;

        while (current != nullptr) {
            if (current->value == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }

        return false;
    }

    void print() const {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            std::cout << "Bucket " << i << ": ";
            HashNode<T>* current = table[i];
            while (current != nullptr) {
                std::cout << current->value << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
};

} // namespace custom

#endif // HASH_HPP
