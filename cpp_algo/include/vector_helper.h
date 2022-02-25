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

template<typename T>
bool isVectorSame(vector<T>& vec1, vector<T>& vec2) {
    int n = vec1.size();
    int m = vec2.size();
    if(n!=m) return false;

    for(int i=0; i<n; i++) {
        if(vec1[i] != vec2[i])  return false;
    }
    return true;
}



#endif // VECTOR_HELPER_H
