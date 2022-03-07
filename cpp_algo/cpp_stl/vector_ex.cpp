//
// Created by LI Tian on 27/2/22.
//

#include <vector>
#include <algorithm>
#include "catch2/catch.hpp"
#include "vector_helper.h"

using namespace std;

void sort2Dvector(vector<vector<int>> & vec) {
    sort(vec.begin(), vec.end(), [](auto &u, auto &v) {
        return u[1] < v[1];
    });
}

TEST_CASE("2d vector sort") {
    SECTION("greedy interval sort") {
        vector<vector<int>> interval = {{0,1}, {0,3}, {1,2}};
        sort2Dvector(interval);
        vector<vector<int>> expect = {{0,1}, {1,2}, {0,3}};
        REQUIRE(is2dVectorSame(interval, expect));
    }
}

TEST_CASE("sub vector") {
    SECTION("range from 1...n-1") {
        // 获取子数组，这个在leetcode 213. House Robber II,
        vector<int> nums = {1,2,3,4,5};
        vector<int> sub = {nums.begin()+1, nums.end()-1};

        cout << *nums.begin() << " " << *(nums.end()-1) << endl;
        cout << *begin(nums) << " " << *(end(nums)-1) << endl;

        REQUIRE(isVectorSame(sub, {2,3,4}));
    }
}

TEST_CASE("low_bound/upper_bound") {
    SECTION("") {
        vector<int> v = {0,1,2,3,4};
        vector<int>::iterator low, up, none, it;
        low = lower_bound(v.begin(), v.end(), 2);
        up = upper_bound(v.begin(), v.end(), 3);
        none = upper_bound(v.begin(), v.end(), 10);

        cout << "low: " << *low << endl;  // low是1-index
        cout << "up: " << *up << endl;  // up 是1-index
        cout << "none: " << *none << endl;  // none

        REQUIRE((low-v.begin()) == 2);
        REQUIRE(up-v.begin() == 4);


        // 如果找不到怎么办？
        it = lower_bound(v.begin(), v.end(), 2);
        if(it != v.end() and *it == 2) {
            cout << "find" << endl;
        } else {
            cout << "cannot find" << endl;
        }
    }
}