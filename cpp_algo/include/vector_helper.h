//
// Created by LI Tian on 4/2/22.
//

#ifndef VECTOR_HELPER_H
#define VECTOR_HELPER_H

#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void printVector(vector<T> & vec) {
    for(auto & each : vec) {
        cout << each << ",";
    }

    cout << endl;
}





#endif // VECTOR_HELPER_H
