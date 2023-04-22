#include <iostream>
#include <string>

#include "../custom/queue.hpp"
#include "queue.hpp"

using namespace custom;
using namespace std;

void menu() {
    cout << "\nArray based Queue\t\n";
    cout << "1. Enqueue\t\t";
    cout << "2. Dequeue\n";
    cout << "3. Front\t\t";
    cout << "4. Back\n";
    cout << "5. Print\t\t";
    cout << "0. Exit\n";
    cout << "  select: ";
}

void arrayQueue() {
    cout << "Enter queue capacity: ";
    int in;
    cin >> in;
    array_queue<int> queue(in);

    int input = 0;
    int c;

    do {
        menu();
        cin >> input;

        switch (input) {
            case 1:
                cout << "Enter an integer: ";
                cin >> c;
                if (queue.full()) {
                    cout << "Queue is full.\n";
                    break;
                }
                if (!queue.enqueue(c)) {
                    cout << "Some error occureced while enqueueing.\n";
                }
                break;
            case 2:
                if (!queue.empty()) {
                    cout << "Dequeued value is " << queue.dequeue() << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                break;
            case 3:
                if (!queue.empty()) {
                    cout << "Front value is " << queue.front() << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                break;
            case 4:
                if (!queue.empty()) {
                    cout << "Back value is " << queue.back() << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                break;
            case 5:
                queue.print();
                break;
        }
    } while (input != 0);
}

void llmenu() {
    cout << "\nArray based Queue\t\n";
    cout << "1. Enqueue\t\t";
    cout << "2. Dequeue\n";
    cout << "3. Front\t\t";
    cout << "4. Back\n";
    cout << "5. Print\t\t";
    cout << "0. Exit\n";
    cout << "  select: ";
}

void linkedListQueue() {
    array_queue<int> queue;

    int input = 0;
    int c;

    do {
        llmenu();
        cin >> input;

        switch (input) {
            case 1:
                cout << "Enter an integer: ";
                cin >> c;
                if (queue.full()) {
                    cout << "Queue is full.\n";
                    break;
                }
                if (!queue.enqueue(c)) {
                    cout << "Some error occureced while enqueueing.\n";
                }
                break;
            case 2:
                if (!queue.empty()) {
                    cout << "Dequeued value is " << queue.dequeue() << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                break;
            case 3:
                if (!queue.empty()) {
                    cout << "Front value is " << queue.front() << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                break;
            case 4:
                if (!queue.empty()) {
                    cout << "Back value is " << queue.back() << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                break;
            case 5:
                queue.print();
                break;
        }
    } while (input != 0);
}
