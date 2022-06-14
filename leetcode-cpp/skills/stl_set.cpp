//
// Created by litian on 28/3/22.
//

/*
 *  掌握：
 *  set的特性
 *  1. 有序性：set will automatically sort the pair in ascending order
 *  2. 无重复性
 */

#include <set>
#include "catch.hpp"

using namespace std;

TEST_CASE("stl::set examples") {
    SECTION("sort pairs") {
        set<pair<int, int>> s;

        s.insert({0,2});
        s.insert({0,1});
        s.insert({5,4});
        s.insert({3,2});

        // 如果是pair，那么按照 first 从小到大排序。
        // set[0] = {0,2}
        // set[1] = {0,1}
        set<pair<int, int>> expect = {{0,2},
                                      {0,1},
                                      {3,2},
                                      {5,4}};

        REQUIRE(expect == s);
    }
}