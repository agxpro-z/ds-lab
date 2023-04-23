#include <iostream>

#include "driver/deque.hpp"
#include "driver/infix_postfix.hpp"
#include "driver/linked_list.hpp"
#include "driver/queue.hpp"
#include "driver/sort.hpp"
#include "driver/stack.hpp"

int main() {
    int in{};

    do {
        std::cout << "\nDS Lab Programs\n";
        std::cout << " 1. Array based stack\n";
        std::cout << " 2. Linked list based stack\n";
        std::cout << " 3. Array based queue\n";
        std::cout << " 4. Linked list based queue\n";
        std::cout << " 5. Array based deque\n";
        std::cout << " 6. Linked list based deque\n";
        std::cout << " 7. Stack using queues\n";
        std::cout << " 8. Queue using stacks\n";
        std::cout << std::endl;
        std::cout << " 9. Infix to postfix\n";
        std::cout << "10. Infix to prefix\n";
        std::cout << "11. Evaluate Postfix expression\n";
        std::cout << "12. Evaluate Prefix expression\n";
        std::cout << std::endl;
        std::cout << "13. Singly linked list\n";
        std::cout << "14. Doubly linked list\n";
        std::cout << "15. Circular singly linked list\n";
        std::cout << "16. Circular doubly linked list\n";
        std::cout << std::endl;
        std::cout << "17. Insertion sort\n";
        std::cout << "18. Merge sort\n";
        std::cout << "19. Quick sort\n";
        std::cout << "20. Count sort\n";
        std::cout << "21. Radix sort\n";
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
            case 9:
                infix_to_postfix_driver();
                break;
            case 10:
                infix_to_prefix_driver();
                break;
            case 11:
                postfix_evaluation_driver();
                break;
            case 12:
                prefix_evaluation_driver();
                break;
            case 13:
                singly_linked_list_driver();
                break;
            case 14:
                doubly_linked_list_driver();
                break;
            case 15:
                circular_singly_linked_list_driver();
                break;
            case 16:
                circular_doubly_linked_list_driver();
                break;
            case 17:
                insertion_sort_driver();
                break;
            case 18:
                merge_sort_driver();
                break;
            case 19:
                quick_sort_driver();
                break;
            case 20:
                count_sort_driver();
                break;
            case 21:
                radix_sort_driver();
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (in != 0);
    return 0;
}
