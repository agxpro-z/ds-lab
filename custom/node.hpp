#ifndef NODE_HPP
#define NODE_HPP

namespace custom {

template<typename T>
class node {
  public:
    node<T>* left;
    node<T>* prev;
    T data;
    node<T>* next;
    node<T>* right;

    // Constructors
    node(T val) : left(nullptr), prev(nullptr), data(val), next(nullptr), right(nullptr) {}
    node(T val, node<T>* next) : left(nullptr), prev(nullptr), data(val), next(next), right(next) {}
    node(node<T>* prev, T val, node<T>* next) : left(prev), prev(prev), data(val), next(next), right(next) {}
};

} // namespace custom

#endif // NODE_HPP