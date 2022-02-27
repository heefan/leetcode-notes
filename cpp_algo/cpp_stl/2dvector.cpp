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