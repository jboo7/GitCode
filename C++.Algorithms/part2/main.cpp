#include <iostream>
#include <vector>
#include <assert.h>

#include "sorted_vector.cpp"

using namespace std;

size_t parent(size_t);
size_t left(size_t);
size_t right(size_t);
template <class T>
void heapify_up(vector<T>& A, size_t index, size_t);
template <class T>
void build_max_heap_up(vector<T>& A);
template <class T>
void heapify_down(vector<T>& A, size_t i, size_t heap_size);
template <class T>
void build_max_heap_down(vector<T>& A);

template<class T>
void heap_sort(vector<T>& A);

template <class T>
ostream& operator<<(ostream& o, const vector<T>& v) {
    o << "{";
    for (const auto& x : v)
        o << x << ", ";
    o << "}";
    return o;
}

int main(int argc, char** argv) {
    vector<int> A({10, 5, 4, 16});

    heap_sort(A);

    cout << A << endl;

    sorted_vector<int> sv();

    return 0;
}

size_t parent(size_t index) {
    assert(index > 0);
    return (index - 1) / 2;
}

size_t left(size_t index) {
    return index * 2 + 1;
}

size_t right(size_t index) {
    return index * 2 + 2;
}

template <class T>
void heapify_up(vector<T>& A, size_t index) {
    // assert(is_heap(A,i ));
    if (index == 0) {
        return;
    }

    size_t p = parent(index);
    if (A[p] < A[index]) {
        swap(A[p], A[index]);
        heapify(A, p);
    }
    // assert(is_heap(A, i + 1));
}

template <class T>
size_t compute_max_3(vector<T>& A, size_t i, size_t left, size_t right, size_t heap_size) {
    if (right >= heap_size) {
        if (left >= heap_size) {
            return i;
        } else {
            if (A[i] > A[left]) {
                return i;
            } else {
                return left;
            }
        }
    } else {
        if (A[i] > A[left] && A[i] > A[right]) {
            return i;
        }
        if (A[left] > A[i] && A[left] > A[right]) {
            return left;
        }
        if (A[right] > A[i] && A[right] > A[left]) {
            return right;
        }
        return i;
    }
}

template <class T>
void heapify_down(vector<T>& A, size_t i, size_t heap_size) {
    if (i >= A.size()) {
        return;
    }

    auto max3 = compute_max_3(A, i, left(i), right(i), heap_size);
    if (i != max3) {
        swap(A[max3], A[i]);
        heapify_down(A, max3, heap_size);
    }
}

template <class T>
void build_max_heap_up(vector<T>& A) {
    // [0, heap_size) U [heap_size, size)
    size_t heap_size = 1;
    while (heap_size < A.size()) {
        heapify_up(A, heap_size);
        heap_size++;
    }
}

template <class T>
void build_max_heap_down(vector<T>& A) {
    auto unprocessed_size = A.size() / 2;
    while (unprocessed_size > 0) {
        unprocessed_size--;
        heapify_down(A, unprocessed_size, A.size());
    }
}

template<class T>
void heap_sort(vector<T>& A) {
    build_max_heap_down(A);

    // [heap ) U [sorted);
    auto begin_sorted = A.size();
    while (begin_sorted > 0) {
        begin_sorted--;
        swap(A[0], A[begin_sorted]);
        auto heap_size = begin_sorted;
        heapify_down(A, 0, heap_size);
    }
}