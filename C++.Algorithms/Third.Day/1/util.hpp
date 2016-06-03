#ifndef _UTIL_HPP
#define _UTIL_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;

typedef int Int;
typedef const int CInt;

typedef vector<int> VecI;
typedef const vector<int> CVecI;

template <class T>
ostream& operator<<(ostream& o, const vector<T>& v) {
    o << "{";
    for (const auto& x : v)
        o << x << ", ";
    o << "}";
    return o;
}

template <class TIter>
void swap_it(TIter x, TIter y) {
    auto t = *x;
    *x = *y;
    *y = t;
}

#endif