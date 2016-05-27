#ifndef _SORT_HPP
#define _SORT_HPP

#include <iostream>
#include <vector>
#include "util.hpp"

using namespace std;

int issorted(const Veci&);
void sort(Veci&);

int issorted(const Veci& v) {
    int res = 0, last;
    if (v.size() == 0) {
        return res;
    }
    last = v[0];
    res = 1;
    for (size_t i = 1; i < v.size(); i++) {
        if (last < v[i]) {
            last = v[i];
        } else {
            res = 0;
            break;
        }
    }
    return res;
}

void sort(Veci& v) {
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = i + 1; j < v.size(); j++) {
            if (v[i] > v[j]) {
                int t = v[i];
                v[i] = v[j];
                v[j] = t;
            }
        }
    }
}

#endif