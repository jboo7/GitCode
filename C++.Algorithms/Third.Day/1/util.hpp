#ifndef _UTIL_HPP
#define _UTIL_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <random>

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

void fill(VecI& v, CInt N) {
    VecI used(N);
    Int l = 0, u = N - 1, n;
    uniform_int_distribution<Int> unif(l,u);
    default_random_engine re;
    for (Int i = 0; i < N; i++) {
        do {
            n = unif(re);
        } while (used[n] != 0);
        used[n] = 1;
        v.push_back(n);
    }
}

#endif