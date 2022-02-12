//
// Created by LI Tian on 2/2/22.
//

#include <vector>
#include <iostream>
#include "vector_ex.h"
using namespace std;

template<typename  T>
void printVector(const vector<T> & vec) {
   for(auto each : vec) {
       cout << each << " ";
   }
   cout << endl;
}

void runVectorExamples() {

    vector<int> vec = {8,1,3,4,5,9};

    //sort in ascending
    sort(vec.begin(), vec.end());
    printVector(vec);

    // sort in descending
    sort(vec.begin(), vec.end(), [](int a, int b) { return a > b;});
    printVector(vec);
}


