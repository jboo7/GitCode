#ifndef _SORT2_HPP
#define _SORT2_HPP

#include <algorithm>

using namespace std;

template <class TIter>
void swap_it(TIter a, TIter b) {
    auto t = *a;
    *a = *b;
    *b = t;
}

template <class TIter>
TIter min_elem(TIter b, TIter e) {
    TIter result = b;
    while (b < e) {
        if (*result > *b) {
            result = b;
        }
        b++;
    }
    return result;
}

template <class TIter>
void naive_sort(TIter b, TIter e) {
    for (TIter i = b; i < e; i++) {
        assert(is_sorted(b, i));
        for (TIter j = i + 1; j < e; j++) {
            if (*i > *j) {
                swap_it(i, j);
            }
        }
        assert(is_sorted(b, i + 1));
    }
}

template <class TIter>
void selection_sort(TIter b, TIter e) {
    for (TIter pivot = b; pivot < e; pivot++) {
        assert(is_sorted(b, pivot));
        swap_it(pivot, min_elem(pivot, e));
        assert(is_sorted(b, pivot + 1));
    }
}

template <class TIter>
void bubble_sort(TIter b, TIter e) {
    for (TIter pivot = e; pivot != b;
         pivot--) {  // unsorted - [b, pivot) U [pivot, e) - sorted
        assert(is_sorted(pivot, e));  // [pivot, e) - sorted
        for (TIter i = b; i < pivot - 1; i++) {
            auto next_i = i + 1;
            if (*i > *next_i) {
                swap_it(i, next_i);
            }
        }
        assert(is_sorted(pivot - 1, e));  // [pivot - 1, e) - sorted
    }
}

template <class TIter>
void insertion_sort(TIter b, TIter e) {
    for (TIter pivot = b; pivot < e;
         pivot++) {                   // sorted [b, pivot) U [pivot, e) unsorted
        assert(is_sorted(b, pivot));  // [b, pivot) - sorted
        for (TIter next_i = pivot + 1; next_i > b && next_i < e;
             next_i--) {          // from pivot + 1 to b
            auto i = next_i - 1;  // next_i is next after i (after pivot first)
            assert(is_sorted(b, i) &&
                   is_sorted(next_i, pivot + 1));  // [b, i) U [i, pivot)
            if (*i > *next_i) {
                swap_it(i, next_i);
            } else {
                break;
            }
            assert(is_sorted(b, i) &&
                   is_sorted(next_i, pivot + 1));  // [b, i) U [i, pivot)
        }
        assert(is_sorted(b, pivot + 1));  // [b, pivot) - sorted
    }
}

template <class TIter>
TIter merge(TIter b1, TIter e1, TIter b2, TIter e2, TIter out) {
    TIter p1 = b1, p2 = b2, b_out = out;
    // [b1, p1) U [p1, e1)
    // [b2, p2) U [p2, e2)
    // [... out) U [out] U (out, ...)

    while (p1 < e1 && p2 < e2) {
        assert(is_sorted(b_out, out));
        assert((p1 - b1) + (p2 - b2) == (out - b_out));
        if (*p1 < *p2) {
            *out = *p1;
            p1++;
        } else {
            *out = *p2;
            p2++;
        }
        assert(is_sorted(b_out, out));
        assert((p1 - b1) + (p2 - b2) == (out - b_out));
        out++;
    }
    out = copy(p2, e2, copy(p1, e1, out));
    assert(is_sorted(b_out, out));
    assert((out - b_out) == (p1 - b1) + (p2 - b2));
    return out;
}

template <class TIter>
void merge_sort(TIter b, TIter e, TIter out) {
    if ((e - b) > 1) {
        TIter m = b + (e - b) / 2;
        merge_sort(b, m, out);
        merge_sort(m, e, out);
        merge(b, m, m, e, out);
    }
}

#endif