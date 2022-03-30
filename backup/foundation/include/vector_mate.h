#ifndef vector_mate_h
#define vector_mate_h

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
void printVector(const vector<T> arr) {

    for(auto const & each : arr) {
        cout << each << ",";
    }
    cout << endl;
}

#endif
