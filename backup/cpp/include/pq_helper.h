//
// Created by litian on 7/7/22.
//

#ifndef LEETCODE_CPP_PQ_HELPER_H
#define LEETCODE_CPP_PQ_HELPER_H

#include <queue>
#include <iostream>

using namespace std;

template<typename T>
void printPQ(const priority_queue<T>& pq) {
    priority_queue<T> pq_copy = pq;
    while(!pq_copy.empty()) {
        cout << pq_copy.top() << endl;
        pq.pop();
    }

    return pq;
}



#endif //LEETCODE_CPP_PQ_HELPER_H
