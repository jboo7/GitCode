#include <iostream>
#include <chrono>

#include "sort.hpp"
#include "search.hpp"
#include "util.hpp"
#include "test.hpp"

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


    v.clear();
    cout << "Generating: ";
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    fill(v, 1000 * 1000 * 1000);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(t2 - t1).count();
    cout << "took " << duration << " ms." << endl;

    cout << "Sorting: ";
    t1 = high_resolution_clock::now();
    sort(v.begin(), v.end());
    t2 = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(t2 - t1).count();
    cout << "took " << duration << " ms." << endl;

    cout << "Searching ternary: ";
    t1 = high_resolution_clock::now();
    VecI::const_iterator result = ternary_search_1<VecI::const_iterator, CInt>(
        v.begin(), v.end(), 150000);
    t2 = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(t2 - t1).count();
    cout << "took " << duration << " ms." << endl;
    cout << "Result: " << (result - v.begin()) << endl;

    cout << "Searching binary: ";
    t1 = high_resolution_clock::now();
    result = bsearch<VecI::const_iterator, CInt>(v.begin(), v.end(), 150000);
    t2 = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(t2 - t1).count();
    cout << "took " << duration << " ms." << endl;
    cout << "Result: " << (result - v.begin()) << endl;

    cout << "Ok." << endl;
}

void test_all_sorts() {
    VecI v({8, 1, 3, 12, 4, 8});
    VecI empty;

    cout << v << endl;
    bubble_sort_2(v.begin(), v.end());
    cout << v << endl;

    cout << empty << endl;
    bubble_sort_2(empty.begin(), empty.end());
    cout << empty << endl;
}

int main(int argc, char** argv) {
    test_all_searches();
    test_all_sorts();
    return 0;
}