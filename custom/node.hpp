#ifndef NODE_HPP
#define NODE_HPP

namespace custom {

template<typename T>
class node {
  public:
    node<T>* prev;
    T data;
    node<T>* next;

    // Constructors
    node(T val) : prev(nullptr), data(val), next(nullptr) {}
    node(T val, node<T>* next) : prev(nullptr), data(val), next(next) {}
    node(node<T>* prev, T val, node<T>* next) : prev(prev), data(val), next(next) {}
};

} // namespace custom

#endif // NODE_HPP