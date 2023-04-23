#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

#include "node.hpp"
#include "queue.hpp"

namespace custom {

template<typename T>
class TreeNode {
  public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

template<typename T>
class BST {
  private:
    TreeNode<T>* root;

    TreeNode<T>* insertNode(TreeNode<T>* node, const T& value) {
        if (node == nullptr) {
            node = new TreeNode<T>(value);
        } else if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    TreeNode<T>* deleteNode(TreeNode<T>* node, const T& value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                TreeNode<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode<T>* temp = node->left;
                delete node;
                return temp;
            } else {
                TreeNode<T>* temp = findMinNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        return node;
    }

    TreeNode<T>* findMinNode(TreeNode<T>* node) {
        if (node == nullptr) {
            return nullptr;
        } else if (node->left == nullptr) {
            return node;
        } else {
            return findMinNode(node->left);
        }
    }

    void printTree(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }

        printTree(node->left);
        std::cout << node->data << " ";
        printTree(node->right);
    }

  public:
    BST() : root(nullptr) {}

    void insert(const T& value) {
        root = insertNode(root, value);
    }

    void remove(const T& value) {
        root = deleteNode(root, value);
    }

    bool search(const T& value) {
        TreeNode<T>* curr = root;
        while (curr != nullptr) {
            if (curr->data == value) {
                return true;
            } else if (value < curr->data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return false;
    }

    void print() {
        printTree(root);
        std::cout << std::endl;
    }
};

/* AVL TREE */
template<typename T>
class AVLNode {
  public:
    T data;
    AVLNode<T>* left;
    AVLNode<T>* right;
    int height;

    AVLNode(T value) {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

template<typename T>
class AVLTree {
  private:
    AVLNode<T>* root;

    int height(AVLNode<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int balanceFactor(AVLNode<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    AVLNode<T>* rightRotate(AVLNode<T>* node) {
        AVLNode<T>* leftChild = node->left;
        AVLNode<T>* rightChildOfLeftChild = leftChild->right;

        // Perform rotation
        leftChild->right = node;
        node->left = rightChildOfLeftChild;

        // Update heights
        node->height = std::max(height(node->left), height(node->right)) + 1;
        leftChild->height = std::max(height(leftChild->left), height(leftChild->right)) + 1;

        // Return new root
        return leftChild;
    }

    AVLNode<T>* leftRotate(AVLNode<T>* node) {
        AVLNode<T>* rightChild = node->right;
        AVLNode<T>* leftChildOfRightChild = rightChild->left;

        // Perform rotation
        rightChild->left = node;
        node->right = leftChildOfRightChild;

        // Update heights
        node->height = std::max(height(node->left), height(node->right)) + 1;
        rightChild->height = std::max(height(rightChild->left), height(rightChild->right)) + 1;

        // Return new root
        return rightChild;
    }

    AVLNode<T>* insert(AVLNode<T>* node, int value) {
        if (node == NULL) {
            return new AVLNode<T>(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        // Update height of current node
        node->height = std::max(height(node->left), height(node->right)) + 1;

        // Get balance factor of node
        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && value < node->left->data) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && value > node->right->data) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode<T>* findMinNode(AVLNode<T>* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    AVLNode<T>* deleteNode(AVLNode<T>* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                AVLNode<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                AVLNode<T>* temp = node->left;
                delete node;
                return temp;
            } else {
                AVLNode<T>* temp = findMinNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (node == nullptr) {
            return node;
        }

        // Update height of current node
        node->height = std::max(height(node->left), height(node->right)) + 1;

        // Get balance factor of node
        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && balanceFactor(node->left) >= 0) {
            return rightRotate(node);
        }

        // Left Right Case
        if (balance > 1 && balanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && balanceFactor(node->right) <= 0) {
            return leftRotate(node);
        }

        // Right Left Case
        if (balance < -1 && balanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }


  public:
    AVLTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    AVLNode<T>* search(int value) {
        AVLNode<T>* node = root;

        while (node != nullptr) {
            if (value == node->data) {
                return node;
            } else if (value < node->data) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        return nullptr;
    }

    void inorderTraversal() {
        inorderTraversal(root);
        std::cout << std::endl;
    }

  private:
    void inorderTraversal(AVLNode<T>* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }
};

} // namespace custom

#endif // TREE_HPP
