#ifndef UTILS_H
#define UTILS_H
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void afiseazaVector(const vector<T> &v)
{
    for (auto &e : v)
        cout << e << "\n";
}
#endif