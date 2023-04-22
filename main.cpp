#include <iostream>

#include "driver/queue.hpp"
#include "driver/stack.hpp"

int main() {
    std::cout << "DS Lab Programs\n";

    int in{};

    do {
        std::cout << "1. Array based stack\n";
        std::cout << "2. Linked list based stack\n";
        std::cout << "3. Array based queue\n";
        std::cout << "4. Linked list based queue\n";
        std::cout << "Select:> ";
        std::cin >> in;

        switch (in) {
            case 1:
                arrayStack();
                break;
            case 2:
                linkedListStack();
                break;
            case 3:
                arrayQueue();
                break;
            case 4:
                linkedListQueue();
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (in != 0);
    return 0;
}
