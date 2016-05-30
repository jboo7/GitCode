#ifndef _SORT_HPP
#define _SORT_HPP

#include <iostream>
#include <vector>
#include "util.hpp"

using namespace std;

template<class T>
void sort(vector<T>& v) {
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

#endif