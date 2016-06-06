#include <iostream>
#include <chrono>

#include "search.hpp"
#include "util.hpp"
#include "test.hpp"

#include "sort2.hpp"

using namespace std;
using namespace std::chrono;

template <class TFunc>
void test_search(TFunc binary_search_impl) {
    int key = 42;

    auto adapter = [binary_search_impl](VecI& v, CInt key) {
        auto result = binary_search_impl(v.begin(), v.end(), key);
        return result != v.end() ? result - v.begin() : -1;
    };

    // degenerated
    test(-1, adapter, VecI(), key);

    // trivial
    test(-1, adapter, VecI({1}), key);
    test(0, adapter, VecI({key}), key);

    // second trivial
    test(-1, adapter, VecI({1, 2}), key);
    test(1, adapter, VecI({1, key}), key);
    test(0, adapter, VecI({key, 103}), key);

    // key not in array
    test(-1, adapter, VecI({1, 2, 3, 4, 5, 41}), key);
    test(-1, adapter, VecI({43, 45, 67, 108}), key);
    test(-1, adapter, VecI({3, 5, 43, 45, 67}), key);

    // key in array
    test(3, adapter, VecI({1, 2, 3, key}), key);
    test(0, adapter, VecI({key, 45, 67, 108}), key);
    test(3, adapter, VecI({1, 2, 3, key, 67, 108}), key);

    // binary specific
    test(3, adapter, VecI({1, 2, 3, key, 67, 108}), key);
    test(3, adapter, VecI({1, 2, 3, key, 67}), key);

    // trying to fail
    test(0, adapter, VecI({0, 1, 2, 3}), 0);
    test(1, adapter, VecI({0, 1, 2, 3}), 1);
    test(2, adapter, VecI({0, 1, 2, 3}), 2);
    test(3, adapter, VecI({0, 1, 2, 3}), 3);
}

void test_all_searches() {
    cout << "Non Recursive Binary Search with Begin-End Iterator and Key"
         << endl;
    test_search(bsearch<VecI::const_iterator, CInt>);
    cout << "Ok." << endl;

    cout << "Recursive Binary Search with Begin-End Iterator and Key" << endl;
    test_search(bsearch_r<VecI::const_iterator, CInt>);
    cout << "Ok." << endl;

    cout << "Binary Search 1" << endl;
    test_search(binary_search_1<VecI::const_iterator, CInt>);
    cout << "Ok." << endl;

    cout << "Binary Search 2" << endl;
    test_search(binary_search_2<VecI::const_iterator, CInt>);
    cout << "Ok." << endl;

    cout << "Uniform Search 1" << endl;
    test_search(uniform_search_1<VecI::const_iterator, CInt>);
    cout << "Ok." << endl;

    cout << "Ternary Search 1" << endl;
    test_search(ternary_search_1<VecI::const_iterator, CInt>);
    cout << "Ok." << endl;

    CInt key = 7;
    VecI v({0, 1, 2, 3, 3, 3, 3, 4, 5, 6, 6, 7, 7, 7, 7, 7});
    cout << v << endl;
    cout << "Key: " << key << endl
         << "Count: "
         << (upper_bound_2<VecI::const_iterator, CInt>(v.begin(), v.end(),
                                                       key) -
             lower_bound_2<VecI::const_iterator, CInt>(v.begin(), v.end(), key))
         << endl;
}

template <class TFunc>
void test_sort(TFunc sort_impl) {
    auto sort_adapter = [sort_impl](VecI v, VecI sorted) {
        sort_impl(v.begin(), v.end());
        test(v.size(), sorted.size());
        for (size_t i = 0; i < v.size() && i < sorted.size(); i++) {
            test(v[i], sorted[i]);
        }
        return 0;
    };

    sort_adapter(VecI(), VecI());
    sort_adapter(VecI({0}), VecI({0}));
    sort_adapter(VecI({1, 0}), VecI({0, 1}));
    sort_adapter(VecI({2, 1, 0}), VecI({0, 1, 2}));
    sort_adapter(VecI({3, 2, 1, 0}), VecI({0, 1, 2, 3}));
    sort_adapter(VecI({4, 3, 2, 1, 0}), VecI({0, 1, 2, 3, 4}));
    sort_adapter(VecI({5, 4, 3, 2, 1, 0}), VecI({0, 1, 2, 3, 4, 5}));
    sort_adapter(VecI({6, 5, 4, 3, 2, 1, 0}), VecI({0, 1, 2, 3, 4, 5, 6}));
    sort_adapter(VecI({7, 6, 5, 4, 3, 2, 1, 0}), VecI({0, 1, 2, 3, 4, 5, 6, 7}));
    sort_adapter(VecI({8, 7, 6, 5, 4, 3, 2, 1, 0}), VecI({0, 1, 2, 3, 4, 5, 6, 7, 8}));
    sort_adapter(VecI({9, 8, 7, 6, 5, 4, 3, 2, 1, 0}), VecI({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
}

void test_all_sorts() {
<<<<<<< HEAD
    /*cout << "Insertion sort" << endl;
    test_sort(insertion_sort_1<VecI::iterator>);
    cout << "Ok." << endl;

    cout << "Bubble sort 1" << endl;
    test_sort(bubble_sort_1<VecI::iterator>);
    cout << "Ok." << endl;

    cout << "Bubble sort 2" << endl;
    test_sort(bubble_sort_2<VecI::iterator>);
    cout << "Ok." << endl;

    cout << "Funny selection sort" << endl;
    test_sort(funny_selection_sort<VecI::iterator>);
    cout << "Ok." << endl;*/
=======
    VecI v({9, 8, 7, 6, 5, 4, 3, 2, 1, 0});

    cout << v << endl;
    insertion_sort(v.begin(), v.end());
    cout << v << endl;
>>>>>>> 2796b4f5151c8651f06a24821d09e926aac449fe
}

int main(int argc, char** argv) {
    test_all_searches();
    test_all_sorts();
    return 0;
}