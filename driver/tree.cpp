#include <iostream>

#include "../custom/tree.hpp"
#include "tree.hpp"

using namespace custom;
using namespace std;

void bst_menu() {
    std::cout << "\n\tBinary Search Tree\n";
    std::cout << "1. Insert\n";
    std::cout << "2. Search\n";
    std::cout << "3. Delete\n";
    std::cout << "4. Print Tree\n";
    std::cout << "0. Exit\n";
    std::cout << " :> ";
}

void bst_driver() {
    int in;

    BST<int> bst;

    do {
        bst_menu();
        std::cin >> in;

        switch(in) {
            case 1:
                std::cout << "Enter an integer: ";
                int x;
                std::cin >> x;
                bst.insert(x);
                break;
            case 2:
                std::cout << "Enter integer key: ";
                int y;
                std::cin >> y;
                bst.search(y) ? std::cout << "Found\n" : std::cout << "Not found\n";
                break;
            case 3:
                std::cout << "Enter integer key: ";
                int z;
                std::cin >> z;
                bst.remove(z);
                std::cout << "Node deleted\n";
                break;
            case 4:
                bst.print();
                break;
        }
    } while (in != 0);
}

void avl_menu() {
    std::cout << "\n\tAVL Tree\n";
    std::cout << "1. Insert\n";
    std::cout << "2. Search\n";
    std::cout << "3. Delete\n";
    std::cout << "4. Print Tree\n";
    std::cout << "0. Exit\n";
    std::cout << " :> ";
}

void avl_driver() {
    int in;

    AVLTree<int> avl;

    do {
        avl_menu();
        std::cin >> in;

        switch(in) {
            case 1:
                std::cout << "Enter an integer: ";
                int x;
                std::cin >> x;
                avl.insert(x);
                break;
            case 2:
                std::cout << "Enter integer key: ";
                int y;
                std::cin >> y;
                avl.search(y) ? std::cout << "Found\n" : std::cout << "Not found\n";
                break;
            case 3:
                std::cout << "Enter integer key: ";
                int z;
                std::cin >> z;
                avl.deleteValue(z);
                std::cout << "Node deleted\n";;
                break;
            case 4:
                avl.inorderTraversal();
                break;
        }
    } while (in != 0);
}
