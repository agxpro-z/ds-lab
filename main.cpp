#include <iostream>

#include "driver/deque.hpp"
#include "driver/graph.hpp"
#include "driver/hash.hpp"
#include "driver/heap.hpp"
#include "driver/infix_postfix.hpp"
#include "driver/linked_list.hpp"
#include "driver/queue.hpp"
#include "driver/sort.hpp"
#include "driver/stack.hpp"
#include "driver/tree.hpp"

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
        std::cout << std::endl;
        std::cout << "22. Binary Search Tree\n";
        std::cout << "23. AVL Tree\n";
        std::cout << std::endl;
        std::cout << "24. Max Heap\n";
        std::cout << "25. Min Heap\n";
        std::cout << "26. Heap Sort\n";
        std::cout << std::endl;
        std::cout << "27. Hashing Linear Probing\n";
        std::cout << "28. Hashing Separate Chaining\n";
        std::cout << std::endl;
        std::cout << "29. Breadth First Search\n";
        std::cout << "30. Depth First Search\n";
        std::cout << "31. Prim's algorithm for MST\n";
        std::cout << "32. Dijkstra algorithm for shortest path\n";
        std::cout << "33. Floyd Warshall algorithm for shortest path\n";
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
            case 22:
                bst_driver();
                break;
            case 23:
                avl_driver();
                break;
            case 24:
                max_heap_driver();
                break;
            case 25:
                min_heap_driver();
                break;
            case 26:
                heap_sort_driver();
                break;
            case 27:
                linear_probing_driver();
                break;
            case 28:
                separate_chaining_driver();
                break;
            case 29:
                bfs_driver();
                break;
            case 30:
                dfs_driver();
                break;
            case 31:
                prims_algo_driver();
                break;
            case 32:
                dijkstra_algo_driver();
                break;
            case 33:
                floyd_algo_driver();
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (in != 0);
    return 0;
}
