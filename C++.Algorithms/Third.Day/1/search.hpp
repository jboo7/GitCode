#ifndef _SEARCH_HPP
#define _SEARCH_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "util.hpp"

using namespace std;

int bsearch(const Veci&, const int&);
VeciCIt bsearch_iter(const Veci&, const int&);
VeciCIt bsearch_iter_recur(const Veci&, const int&);

VeciCIt binary_search_3_lower_bound(VeciCIt&, VeciCIt&, const int&);

int bsearch(const Veci& v, const int& key) {
    int l = 0;
    int r = v.size();
    int mid = 0;

    while (l < r) {
        mid = l + (r - l) / 2;
        if (key < v[mid]) {
            r = mid;
        } else if (key > v[mid]) {
            l = mid + 1;
        } else {
            return mid;
        }
    }
    return v.size();
}

VeciCIt bsearch_iter(const Veci& v, const int& key) {
    VeciCIt l = v.begin(), r = v.end(), mid;

    while (l < r) {
        mid = l + (r - l) / 2;

        if (key < *mid) {
            r = mid;
        } else if (key > *mid) {
            l = mid + 1;
        } else {
            return mid;
        }
    }
    return v.end();
}

VeciCIt bsearch_iter_recur(VeciCIt begin, VeciCIt end, const int& key) {
    assert(is_sorted(begin, end));
    auto size = end - begin;
    if (size == 0) {
        return end;
    }
    if (size == 1) {
        return *begin == key ? begin : end;
    }

    auto m = begin + (end - begin) / 2;
    if (key < *m) {
        return bsearch_iter_recur(begin, m, key);
    } else if (key > *m) {
        return bsearch_iter_recur(m + 1, end, key);
    } else {
        return m;
    }
}

VeciCIt binary_search_3_lower_bound(VeciCIt& begin, VeciCIt& end, const int& key) {
    assert(is_sorted(begin, end));
    while (begin < end) {
        VeciCIt mid = begin + (end - begin) / 2;

        if (key < *mid) {
            end = mid;
        } else {
            begin = mid + 1;
        }
    }
    return begin;
}

#endif