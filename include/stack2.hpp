// Copyright 2021 by SovesT

#ifndef INCLUDE_STACK2_HPP_
#define INCLUDE_STACK2_HPP_

#include <stdexcept>
#include <utility>

using std::forward;
using std::logic_error;

template <typename T>

class Stack2 {
 private:
  T* ptr;
  size_t length;

 public:
  Stack2() {
    ptr = nullptr;
    length = 0;
  }

  ~Stack2() { delete[] ptr; }

  template <typename... Args>
  void push_emplace(Args&&... value) {
    T* data = new T[length];
    T obj(value...);
    if (length) {
      for (unsigned int i = 0; i < length; ++i) data[i] = forward<T>(ptr[i]);
    }
    delete[] ptr;
    ptr = new T[++length];
    for (unsigned int i = 0; i < length - 1; ++i) ptr[i] = forward<T>(data[i]);
    delete[] data;
    ptr[length - 1] = forward<T>(obj);
  }

  void push(T&& value) {
    T* data = new T[length];
    if (length) {
      for (unsigned int i = 0; i < length; ++i) data[i] = forward<T>(ptr[i]);
    }
    delete[] ptr;
    ++length;
    ptr = new T[length];
    for (unsigned int i = 0; i < length - 1; ++i) ptr[i] = forward<T>(data[i]);
    delete[] data;
    ptr[length - 1] = forward<T>(value);
  }

  const T& head() const {
    if (length)
      return ptr[length - 1];
    else
      throw logic_error("Stack is empty!");
  }

  T pop() {
    if (length) {
      T* data = new T[length];
      for (unsigned int i = 0; i < length; ++i) data[i] = forward<T>(ptr[i]);
      delete[] ptr;
      ptr = new T[--length];
      for (unsigned int i = 0; i < length; ++i) ptr[i] = forward<T>(data[i]);
      T temp = data[length];
      delete[] data;
      return temp;
    } else {
      throw logic_error("Stack is empty!");
    }
  }
};

#endif  // INCLUDE_STACK2_HPP_
