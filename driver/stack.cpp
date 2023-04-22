#include <iostream>

#include "../custom/stack.hpp"

using namespace custom;
using namespace std;

void arrayStack() {
    cout << "Enter stack capacity: ";
    int in;
    cin >> in;
    array_stack<int> s(in);

    int c;
    do {
        cout << "\nArray Based Stack: \n";
        cout << "1. Push\t\t";
        cout << "2. Pop\n";
        cout << "3. Top\t\t";
        cout << "4. Empty?\n";
        cout << "5. Full?\t";
        cout << "6. Size\n";
        cout << "7. Print stack\t";
        cout << "0. Exit\n";
        cout << "Select: ";
        cin >> in;
        
        switch (in) {
            case 1:
                if (s.full()) {
                    cout << "Stack is full.\n";
                } else {
                    cout << "Enter an integer: ";
                    cin >> c;
                    if (s.push(c)) {
                        cout << c << " pushed into stack.\n";
                    } else {
                        cout << "Unable to push into stack\n";
                    }
                }
                break;
            case 2:
                if (s.empty()) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << s.top() << endl;
                    s.pop();
                }
                break;
            case 3:
                if (s.empty()) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << s.top() << endl;
                }
                break;
            case 4:
                if (s.empty()) {
                    cout << "Stack is empty\n";
                } else {
                    cout << "Stack is not empty\n";
                }
                break;
            case 5:
                if (s.full()) {
                    cout << "Stack is full\n";
                } else {
                    cout << "Stack is not full\n";
                }
                break;
            case 6:
                cout << "Stack size is " << s.size() << ".\n";
                break;
            case 7:
                cout << "Stack: \n";
                s.print();
                break;
            case 0:
            default:
                break;
        }
    } while (in != 0);
}

void linkedListStack() {
    int in;
    linked_list_stack<int> s;

    int c;
    do {
        cout << "\nLinked List Based Stack: \n";
        cout << "1. Push\t\t";
        cout << "2. Pop\n";
        cout << "3. Top\t\t";
        cout << "4. Empty?\n";
        cout << "6. Size\t\t";
        cout << "7. Print stack\n";
        cout << "0. Exit\n";
        cout << "Select: ";
        cin >> in;
        
        switch (in) {
            case 1:
                cout << "Enter an integer: ";
                cin >> c;
                if (s.push(c)) {
                    cout << c << " pushed into stack.\n";
                } else {
                    cout << "Unable to push into stack\n";
                }
                break;
            case 2:
                if (s.empty()) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << s.top() << endl;
                    s.pop();
                }
                break;
            case 3:
                if (s.empty()) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << s.top() << endl;
                }
                break;
            case 4:
                if (s.empty()) {
                    cout << "Stack is empty\n";
                } else {
                    cout << "Stack is not empty\n";
                }
                break;
            case 5:
                cout << "Stack size is " << s.size() << ".\n";
                break;
            case 7:
                cout << "Stack: \n";
                s.print();
                break;
            case 0:
            default:
                break;
        }
    } while (in != 0);
}