#include <iostream>
#include <string>

#include "../custom/deque.hpp"
#include "deque.hpp"

using namespace custom;
using namespace std;

void array_deque_menu() {
    cout << "\nArray based Deque\n";
    cout << "1. Enqueue Front\t";
    cout << "2. Dequeue Front\n";
    cout << "3. Enqueue Rear\t\t";
    cout << "4. Dequeue Rear\n";
    cout << "5. Size\t\t\t";
    cout << "6. Empty?\n";
    cout << "7. Print\t\t";
    cout << "0. Exit\n";
    cout << "  select: ";
}

void arrayDeque() {
    cout << "Enter deque capacity: ";
    int in;
    cin >> in;
    array_deque<int> dequeue(in);

    int input = 0;
    int c;

    do {
        array_deque_menu();
        cin >> input;

        switch (input) {
            case 1:
                cout << "Enter an integer: ";
                cin >> c;
                if (dequeue.full()) {
                    cout << "DeQueue is full.\n";
                    break;
                }
                if (!dequeue.push_front(c)) {
                    cout << "Some error occureced while enqueueing.\n";
                }
                break;
            case 2:
                if (!dequeue.empty()) {
                    cout << "Front dequeued value is " << dequeue.pop_front() << endl;
                } else {
                    cout << "DeQueue is empty.\n";
                }
                break;
            case 3:
                cout << "Enter an integer: ";
                cin >> c;
                if (dequeue.full()) {
                    cout << "DeQueue is full.\n";
                    break;
                }
                if (!dequeue.push_back(c)) {
                    cout << "Some error occureced while enqueueing.\n";
                }
                break;
            case 4:
                if (!dequeue.empty()) {
                    cout << "Dequeued value is " << dequeue.pop_back() << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                break;
            case 5:
                std::cout << "Deque size = " << dequeue.size() << std::endl;
                break;
            case 6:
                if (dequeue.empty()) {
                    std::cout << "Deque is empty.\n";
                } else {
                    std::cout << "Deque is not empty.\n";
                }
                break;
            case 7:
                dequeue.print();
                break;
        }
    } while (input != 0);
}

void linked_list_deque_menu() {
    cout << "\nArray based Deque\n";
    cout << "1. Enqueue Front\t";
    cout << "2. Dequeue Front\n";
    cout << "3. Enqueue Rear\t\t";
    cout << "4. Dequeue Rear\n";
    cout << "5. Size\t\t\t";
    cout << "6. Empty?\n";
    cout << "7. Print\t\t";
    cout << "0. Exit\n";
    cout << "  select: ";
}

void linkedListDeque() {
    linked_list_deque<int> dequeue;

    int input = 0;
    int c;

    do {
        array_deque_menu();
        cin >> input;

        switch (input) {
            case 1:
                cout << "Enter an integer: ";
                cin >> c;
                if (!dequeue.push_front(c)) {
                    cout << "Some error occureced while enqueueing.\n";
                }
                break;
            case 2:
                if (!dequeue.empty()) {
                    cout << "Front dequeued value is " << dequeue.pop_front() << endl;
                } else {
                    cout << "DeQueue is empty.\n";
                }
                break;
            case 3:
                cout << "Enter an integer: ";
                cin >> c;
                if (!dequeue.push_back(c)) {
                    cout << "Some error occureced while enqueueing.\n";
                }
                break;
            case 4:
                if (!dequeue.empty()) {
                    cout << "Dequeued value is " << dequeue.pop_back() << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                break;
            case 5:
                std::cout << "Deque size = " << dequeue.size() << std::endl;
                break;
            case 6:
                if (dequeue.empty()) {
                    std::cout << "Deque is empty.\n";
                } else {
                    std::cout << "Deque is not empty.\n";
                }
                break;
            case 7:
                dequeue.print();
                break;
        }
    } while (input != 0);
}