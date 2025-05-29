#include <iostream>
#include <forward_list>

template <typename T>
bool includeInForwardList(std::forward_list<T> list, T elem) {
  for (T e : list) {
    if (e == elem) {
      return true;
    }
  }
  return false;
}