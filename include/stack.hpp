// Copyright 2021 SovesT

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_

#include <stdexcept>

template <typename T>

class Node {
 public:
  T data;
  Node<T>* next;
};

template <typename T>

class Stack {
 private:
  Node<T>* top;
  int length;

 public:
  Stack() {
    top = nullptr;
    length = 0;
  }

  ~Stack() { delete top; }

  void push(T&& value) {
    Node<T>* newn = new Node<T>();
    newn->data = value;
    newn->next = top;
    top = newn;
    length++;
  }

  void push(const T& value) {
    Node<T>* newn = new Node<T>();
    newn->data = value;
    newn->next = top;
    top = newn;
    length++;
  }

  void pop() {
    if (length) {
      Node<T>* deleteNode = top;
      top = top->next;
      delete deleteNode;
      length--;
    } else {
      throw std::logic_error("Stack is empty!");
    }
  }

  

  const T& head() const { return top->data; }
};

#endif  // INCLUDE_EXAMPLE_HPP_
