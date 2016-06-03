#ifndef _SORT_HPP
#define _SORT_HPP

#include "util.hpp"
#include <iostream>
#include <vector>

using namespace std;

template <class T> void sort(std::vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    for (auto j = i + 1; j != v.end(); j++) {
      if (*i < *j) {
        auto t = *i;
        *i = *j;
        *j = t;
      }
    }
  }
}

template <class TIter> void sort_1(TIter begin, TIter end) {
  for (TIter i = begin; i != end; i++) {
    for (TIter j = i + 1; j != end; j++) {
      if (*i > *j) {
        swap1(i, j);
      }
    }
  }
}

template <class TIter> TIter min1(TIter begin, TIter end) {
  TIter min = begin;
  while (begin < end) {
    if (*begin < *min) {
      min = begin;
    }
    begin++;
  }
  return min;
}

template <class TIter> void sort_2(TIter begin, TIter end) {
  for (TIter i = begin; i != end; i++) {
    auto m = min1(i, end); // O(e - i)
    if (i != m)            // O(1)
      swap1(i, m);         // O(1)
  }
}

template <class TIter> void funny_selection_search(TIter begin, TIter end) {
  for (TIter i = begin; i != end; i++)
    swap1(i, min1(i, end));
}

template <class TIter> void bubble_sort_1(TIter b, TIter e) {
  bool flag = true;
  while (flag) {
    flag = false;
    for (TIter i = b + 1; i < e; i++) {
      if (*(i - 1) > *i) {
        swap1(i - 1, i);
        flag = true;
      }
    }
  }
}

template <class TIter> void bubble_sort_2(TIter b, TIter e) {
  for (TIter pivot = e; pivot != b; pivot--) {
    for (TIter i = b + 1; i < pivot; i++) {
      auto prev_i = i - 1;
      cout << *prev_i << " " << *i << ", ";
      if (*prev_i > *i) {
        swap1(prev_i, i);
      }
    }
    cout << endl;
  }
}

template <class TIter>
void insertion_sort_1(TIter b, TIter e) {
    for () {
        assert(is_sorted(b, pivot));
        for (TIter i = pivot; i != b; i--) {
            // insert *pivot to [begin, pivot)
            assert(is_sorted(b, i) && is_sorted(i, pivot+1));
            auto next_i = i+1;
            if (*next_i < *i) {
                swap1(i, next_i);
            } else {
                break;
            }
            assert(is_sorted(b, i) && is_sorted(i, pivot+1));
        }
        assert(is_sorted(b, pivot));
    }
}

#endif