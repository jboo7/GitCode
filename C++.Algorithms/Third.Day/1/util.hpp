#ifndef _UTIL_HPP
#define _UTIL_HPP

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

typedef vector<int> Veci;
typedef vector<int>::iterator VeciIt;
typedef vector<int>::const_iterator VeciCIt;

void fill(Veci&, const int&);
void show(const Veci&);

void fill(Veci& v, const int& N) {
    vector<int> u(N);
    int n;
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++) {
        while (u[n = rand() % N] != 0)
            ;
        u[n] = 1;
        v.push_back(n);
    }
}

void show(const Veci& v) {
    cout << "Vector v:" << endl;
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

#endif