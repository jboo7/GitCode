#ifndef _TEST_HPP
#define _TEST_HPP

#include <iostream>
#include <iomanip>
#include <cassert>
#include <algorithm>
#include "util.hpp"

using namespace std;

template <class T, class TFunc, class P1>
void test(T expected, TFunc f, P1 p1) {
    auto result = f(p1);
    if (expected != result) {
        cout << "Error: "
             << "expected - " << expected << ", got - " << result << endl;
        cout << p1 << endl;
        assert(false);
    }
}

template <class T, class TFunc, class P1, class P2>
void test(T expected, TFunc f, P1 p1, P2 p2) {
    auto result = f(p1, p2);
    if (expected != result) {
        cout << "Error: "
             << "expected - " << expected << ", got - " << result << endl;
        cout << p1 << endl << p2 << endl;
        assert(false);
    }
}

#endif