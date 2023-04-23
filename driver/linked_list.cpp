#include <iostream>

#include "../custom/linked_list.hpp"
#include "linked_list.hpp"

using namespace custom;
using namespace std;

void singly_linked_list_menu() {
    cout << "\tLinked List\n\n";
    cout << "1. Insert Begin\t";
    cout << "2. Delete Begin\n";
    cout << "3. Insert End\t";
    cout << "4. Delete End\n";
    cout << "5. Size\t\t";
    cout << "6. isEmpty\n";
    cout << "7. Print List\t";
    cout << "0. Exit\n";
    cout << " select:> ";
}

void singly_linked_list_driver() {
    int in = 0;

    singly_linked_list<int> ll;
    int val;

    do {
        singly_linked_list_menu();

        cin >> in;

        switch (in) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                ll.insert_begin(val);
                break;
            case 2:
                cout << ll.delete_begin() << endl;
                break;
            case 3:
                cout << "Enter value: ";
                cin >> val;
                ll.insert_end(val);
                break;
            case 4:
                cout << ll.delete_end() << endl;
                break;
            case 5:
                cout << ll.size() << endl;
                break;
            case 6:
                if (ll.empty())
                    cout << "Linked list is empty.\n";
                else
                    cout << "Linked list is not empty.\n";
                break;
            case 7:
                ll.print();
                cout << endl;
                break;
            default:
                break;
        }
    } while (in != 0);
}

void doubly_linked_list_menu() {
    cout << "\tDoubly Linked List\n\n";
    cout << "1. Insert Begin\t";
    cout << "2. Delete Begin\n";
    cout << "3. Insert End\t";
    cout << "4. Delete End\n";
    cout << "5. Size\t\t";
    cout << "6. isEmpty\n";
    cout << "7. Print List\t";
    cout << "0. Exit\n";
    cout << " select:> ";
}

void doubly_linked_list_driver() {
    int in = 0;

    doubly_linked_list<int> ll;
    int val;

    do {
        doubly_linked_list_menu();

        cin >> in;

        switch (in) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                ll.insert_begin(val);
                break;
            case 2:
                cout << ll.delete_begin() << endl;
                break;
            case 3:
                cout << "Enter value: ";
                cin >> val;
                ll.insert_end(val);
                break;
            case 4:
                cout << ll.delete_end() << endl;
                break;
            case 5:
                cout << ll.size() << endl;
                break;
            case 6:
                if (ll.empty())
                    cout << "Linked list is empty.\n";
                else
                    cout << "Linked list is not empty.\n";
                break;
            case 7:
                ll.print();
                cout << endl;
                break;
            default:
                break;
        }
    } while (in != 0);
}

void circular_singly_linked_list_menu() {
    cout << "\tCircular Linked List\n\n";
    cout << "1. Insert Begin\t";
    cout << "2. Delete Begin\n";
    cout << "3. Insert End\t";
    cout << "4. Delete End\n";
    cout << "5. Size\t\t";
    cout << "6. isEmpty\n";
    cout << "7. Print List\t";
    cout << "0. Exit\n";
    cout << " select:> ";
}

void circular_singly_linked_list_driver() {
    int in = 0;

    circular_singly_linked_list<int> ll;
    int val;

    do {
        circular_singly_linked_list_menu();

        cin >> in;

        switch (in) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                ll.insert_begin(val);
                break;
            case 2:
                cout << ll.delete_begin() << endl;
                break;
            case 3:
                cout << "Enter value: ";
                cin >> val;
                ll.insert_end(val);
                break;
            case 4:
                cout << ll.delete_end() << endl;
                break;
            case 5:
                cout << ll.size() << endl;
                break;
            case 6:
                if (ll.empty())
                    cout << "Linked list is empty.\n";
                else
                    cout << "Linked list is not empty.\n";
                break;
            case 7:
                ll.printc();
                cout << endl;
                break;
            default:
                break;
        }
    } while (in != 0);
}

void circular_doubly_linked_list_menu() {
    cout << "\tDoubly Linked List\n\n";
    cout << "1. Insert Begin\t";
    cout << "2. Delete Begin\n";
    cout << "3. Insert End\t";
    cout << "4. Delete End\n";
    cout << "5. Size\t\t";
    cout << "6. isEmpty\n";
    cout << "7. Print List\t";
    cout << "0. Exit\n";
    cout << " select:> ";
}

void circular_doubly_linked_list_driver() {
    int in = 0;

    circular_doubly_linked_list<int> ll;
    int val;

    do {
        circular_doubly_linked_list_menu();

        cin >> in;

        switch (in) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                ll.insert_begin(val);
                break;
            case 2:
                cout << ll.delete_begin() << endl;
                break;
            case 3:
                cout << "Enter value: ";
                cin >> val;
                ll.insert_end(val);
                break;
            case 4:
                cout << ll.delete_end() << endl;
                break;
            case 5:
                cout << ll.size() << endl;
                break;
            case 6:
                if (ll.empty())
                    cout << "Linked list is empty.\n";
                else
                    cout << "Linked list is not empty.\n";
                break;
            case 7:
                ll.printc();
                cout << endl;
                break;
            default:
                break;
        }
    } while (in != 0);
}
