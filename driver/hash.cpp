#include <iostream>

#include "../custom/hash.hpp"
#include "hash.hpp"

using namespace custom;
using namespace std;

void linear_probing_menu() {
    std::cout << "\n\tHashing Linear Probing\n";
    std::cout << "1. Insert\n";
    std::cout << "2. Search\n";
    std::cout << "3. Delete\n";
    std::cout << "4. Print Hash Table\n";
    std::cout << "0. Exit\n";
    std::cout << " :> ";
}

void linear_probing_driver() {
    cout << "Enter hash table size: ";
    int in;
    cin >> in;

    HashTable<int> hash(in);

    do {
        linear_probing_menu();
        std::cin >> in;

        switch(in) {
            case 1:
                std::cout << "Enter an integer: ";
                int x;
                std::cin >> x;
                hash.insert(x);
                break;
            case 2:
                std::cout << "Enter integer key: ";
                int y;
                std::cin >> y;
                hash.search(y) ? std::cout << "Key found\n" : std::cout << "Key not found\n";
                break;
            case 3:
                std::cout << "Enter integer key: ";
                int z;
                std::cin >> z;
                hash.remove(z);
                break;
            case 4:
                hash.print();
                break;
        }
    } while (in != 0);
}


void separate_chaining_menu() {
    std::cout << "\n\tHashing Separate Chaining\n";
    std::cout << "1. Insert\n";
    std::cout << "2. Search\n";
    std::cout << "3. Delete\n";
    std::cout << "4. Print Hash Table\n";
    std::cout << "0. Exit\n";
    std::cout << " :> ";
}

void separate_chaining_driver() {
    int in;

    HashTableSC<int> hash;

    do {
        separate_chaining_menu();
        std::cin >> in;

        switch(in) {
            case 1:
                std::cout << "Enter an integer: ";
                int x;
                std::cin >> x;
                hash.insert(x);
                break;
            case 2:
                std::cout << "Enter integer key: ";
                int y;
                std::cin >> y;
                hash.search(y) ? std::cout << "Key found\n" : std::cout << "Key not found\n";
                break;
            case 3:
                std::cout << "Enter integer key: ";
                int z;
                std::cin >> z;
                hash.remove(z);
                break;
            case 4:
                hash.print();
                break;
        }
    } while (in != 0);
}
