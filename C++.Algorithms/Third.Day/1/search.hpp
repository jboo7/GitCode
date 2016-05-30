#ifndef _SEARCH_HPP
#define _SEARCH_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "util.hpp"

using namespace std;

template <class TIter, class T>
TIter bsearch(TIter begin, TIter end, T key) {
    assert(is_sorted(begin, end));
    TIter l = begin, r = end, mid;
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
    return end;
}

template <class TIter, class T>
TIter bsearch_r(TIter begin, TIter end, T key) {
    assert(is_sorted(begin, end));
    if (begin >= end) {
        return end;
    }
    auto m = begin + (end - begin) / 2;
    if (key < *m) {
        auto r = bsearch_r(begin, m, key);
        return r == m ? end : r;
    } else if (key > *m) {
        return bsearch_r(m + 1, end, key);
    } else {
        return m;
    }
}

template <class TIter, class T>
TIter binary_search_1(TIter begin, TIter end, T key) {
    assert(is_sorted(begin, end));
    auto size = end - begin;
    if (size == 0) {
        return end;
    }
    if (size == 1) {
        return (*begin) == key ? begin : end;
    }
    auto m = begin + (end - begin) / 2;
    if (key < *m)  // [begin, m)
    {
        auto r = binary_search_1(begin, m, key);
        return m == r ? end : r;
    } else  // [m, end)
        return binary_search_1(m, end, key);
}

template <class TIter, class T>
TIter binary_search_2(TIter begin, TIter end, T key) {
    assert(is_sorted(begin, end));
    auto size = end - begin;
    if (size == 0) {
        return end;
    }

    assert(size > 0);
    auto m = begin + (end - begin) / 2;

    // [begin m) [m] (m end)
    if (key < *m)  // [begin, m)
    {
        auto r = binary_search_2(begin, m, key);
        return m == r ? end : r;
    } else if (*m < key)  // [m+1, end)
    {
        return binary_search_2(m + 1, end, key);
    } else  // *m == key
    {
        return m;
    }
}

template <class TIter, class T>
TIter lower_bound_1(TIter begin, TIter end, T key) {
    assert(is_sorted(begin, end));
    while (begin < end) {
        auto m = begin + (end - begin) / 2;
        if (key > *m) {
            begin = m + 1;
        } else {
            end = m;
        }
    }
    return end;
}

template <class TIter, class T>
TIter lower_bound_2(TIter begin, TIter end, T key) {
    assert(is_sorted(begin, end));
    if (begin == end) {
        return end;
    }
    auto m = begin + (end - begin) / 2;
    return (key > *m) ? lower_bound_2(m + 1, end, key)
                      : lower_bound_2(begin, m, key);
}

template <class TIter, class T>
TIter upper_bound_1(TIter begin, TIter end, T key) {
    assert(is_sorted(begin, end));
    while (begin < end) {
        // [begin m) [m] (m end)
        auto m = begin + (end - begin) / 2;
        if (key < *m) {
            end = m;  // [begin, m)
        } else {
            begin = m + 1;  // [m+1, end)
        }
    }
    return begin;
}

template <class TIter, class T>
TIter upper_bound_2(TIter begin, TIter end, T key) {
    assert(is_sorted(begin, end));
    if (begin == end) {
        return end;
    }
    auto m = begin + (end - begin) / 2;
    return (key < *m) ? upper_bound_2(begin, m, key)
                      : upper_bound_2(m + 1, end, key);
}

template <class TIter, class T>
TIter uniform_search_1(TIter begin, TIter end, T key) {
    assert(is_sorted(begin, end));
    if (begin == end) {
        return end;
    }
    TIter l = begin, r = end - 1, m;
    while ((*l) < key && (*r) > key) {
        m = l + (key - (*l)) * (r - l) / ((*r) - (*l));
        if (key < *m) {
            r = m - 1;
        } else if (key > *m) {
            l = m + 1;
        } else {
            return m;
        }
    }
    if (*l == key) {
        return l;
    }
    if (*r == key) {
        return r;
    }
    return end;
}

template <class TIter, class T>
TIter binary_search_3(TIter begin, TIter end, T key) {}

template <class TIter, class T>
TIter ternary_search_1(TIter begin, TIter end, T key) {
    TIter l = begin, r = end, m1, m2;
    assert(is_sorted(begin, end));

    while (l < r) {
        auto len = r - l;
        m1 = l + len / 3;
        m2 = l + (2 * len) / 3;

        if (key < *m1) {
            r = m1;
        } else if (*m1 < key) {
            if (key < *m2) {
                l = m1 + 1;
                r = m2;
            } else if (*m2 < key) {
                l = m2 + 1;
            } else {
                return m2;
            }
        } else {
            return m1;
        }
    }
    return end;
}

#endif