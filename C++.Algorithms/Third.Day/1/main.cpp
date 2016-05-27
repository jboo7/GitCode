#include <iostream>
#include <time.h>

#include "sort.hpp"
#include "search.hpp"
#include "util.hpp"
#include "test.hpp"

using namespace std;

void test_all_binary_searches();
template <class TFunc>
void test_binary_search(TFunc binary_search_impl);

int main(int argc, char** argv) {
    test_all_binary_searches();

    return 0;
}

void test_all_binary_searches() {
    auto bsearch_adapter = [](const Veci& v, const int& key) {
        auto result = bsearch(v, key);
        return result == v.size() ? -1 : result;
    };
    test_binary_search(bsearch_adapter);

    auto bsearch_iter_adapter = [](const Veci& v, const int& key) {
        auto result = bsearch_iter(v, key);
        return result == v.end() ? -1 : result - v.begin();
    };
    test_binary_search(bsearch_iter_adapter);

    /*auto bsearch_iter_recur_adapter = [](const Veci& v, const int& key) {
        auto result = bsearch_iter_recur(v.begin(), v.end(), key);
        return result == v.end() ? -1 : result - v.begin();
    };
    test_binary_search(bsearch_iter_recur_adapter);*/

    test_binary_search([](const Veci& v, const int& key) {
        auto result = binary_search_3_lower_bound(v.begin(), v.end(), key);
        return result == v.end() ? -1 : result - v.begin();
    });
}

template <class TFunc>
void test_binary_search(TFunc binary_search_impl) {
    int key = 42;

    // degenerated
    test(-1, binary_search_impl, Veci(), key);

    // trivial
    test(-1, binary_search_impl, Veci({1}), key);
    test(0, binary_search_impl, Veci({42}), key);

    // second trivial
    test(-1, binary_search_impl, Veci({1, 2}), key);
    test(1, binary_search_impl, Veci({1, 42}), key);
    test(0, binary_search_impl, Veci({42, 103}), key);

    // key not in array
    test(-1, binary_search_impl, Veci({1, 2, 3, 4, 5, 41}), key);
    test(-1, binary_search_impl, Veci({43, 45, 67, 108}), key);
    test(-1, binary_search_impl, Veci({3, 5, 43, 45, 67}), key);

    // key in array
    test(3, binary_search_impl, Veci({1, 2, 3, 42}), key);
    test(0, binary_search_impl, Veci({42, 45, 67, 108}), key);
    test(3, binary_search_impl, Veci({1, 2, 3, 42, 67, 108}), key);

    // binary specific
    test(3, binary_search_impl, Veci({1, 2, 3, 42, 67, 108}), key);
    test(3, binary_search_impl, Veci({1, 2, 3, 42, 67}), key);

    // failing
    test(0, binary_search_impl, Veci({0, 1, 2, 3}), 0);
    test(1, binary_search_impl, Veci({0, 1, 2, 3}), 1);
    test(2, binary_search_impl, Veci({0, 1, 2, 3}), 2);
    test(3, binary_search_impl, Veci({0, 1, 2, 3}), 3);
}