#include <iostream>
#include <vector>
#include "../include/vector_mate.h"

void heapify(vector<int> & arr, int n, int i) {
    int smallest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n and arr[l] <= arr[smallest]) smallest = l;
    if(r<n and arr[r] <= arr[smallest]) smallest = r;
    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapSort(vector<int> & arr) {
    int n = arr.size();
    for(int i=n/2-1;  i>=0; i--) {
        heapify(arr, n, 0);
    }

    for(int i=n-1; i>=0; i--) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12,11,11,13, 13,5,7,6};

    heapSort(arr);
    printVector(arr);
    return 0;
}
