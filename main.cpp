#include <iostream>

#include "driver/deque.hpp"
#include "driver/queue.hpp"
#include "driver/stack.hpp"

int main() {
    int in{};

    do {
        std::cout << "\nDS Lab Programs\n";
        std::cout << "1. Array based stack\n";
        std::cout << "2. Linked list based stack\n";
        std::cout << "3. Array based queue\n";
        std::cout << "4. Linked list based queue\n";
        std::cout << "5. Array based deque\n";
        std::cout << "6. Linked list based deque\n";
        std::cout << "7. Stack using queues\n";
        std::cout << "8. Queue using stacks\n";
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
            case 5:
                arrayDeque();
                break;
            case 6:
                linkedListDeque();
                break;
            case 7:
                stack_of_queue();
                break;
            case 8:
                queue_of_stack();
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (in != 0);
    return 0;
}
