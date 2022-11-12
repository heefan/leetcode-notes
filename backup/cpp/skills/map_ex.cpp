//
// Created by LI Tian on 23/2/22.
//


#include <map>
#include <string_view>
#include <iostream>
#include <algorithm>
#include "catch.hpp"
#define  CATCH_MAIN_CONFIG

using namespace  std;

void print_map(string_view comment, const map<string, int>& m) {
    cout << comment;
    for(const auto& [key, value] : m)
        cout << '[' << key << "] = " << value << "; ";
    cout << endl;
}

TEST_CASE( "cpp20 usage") {
    SECTION("usage") {
        map<string, int> m {
                {"CPU", 20},
                {"GPU", 15},
                {"ARM", 10}};
        print_map("1) init map", m);

        m["CPU"] = 25;
        m["GPU"] = 30;
        print_map("2) init map", m);

        m.erase("GPU");

        erase_if(m, [](const auto& pair) {
            return pair.second > 25;
        });

        REQUIRE(m.size() == 2);
    }
}

/// 知识点：
/// sample reference: https://en.cppreference.com/w/cpp/container/map
/// 1. 相比较 unordered_map, map会默认排序。 比如这里按照字母顺序排序。 [A]RM, [C]PU, [G]PU



/// 发散：
/// 这有点类似于 priority queue和queue， queue不会做排序，但是priority queue是按照顺序进入queue的。
///  std::priority_queue


/// Deep Dive:  std::map的时间复杂度
/// map是 red-black Tree实现方法。
///  一般来说：
///  搜索的时间复杂度：O(logN) => 相比unordered_map O(1)
///  插入的时间复杂度：O(logN)

/// Discussion: https://stackoverflow.com/leetcode/21740893/what-is-the-time-complexity-of-stdmap

///                   | map                | unordered_map
///  ---------------------------------------------------------
///  Ordering        | increasing  order   | no ordering
///                  | (by default)        |
///
///  Implementation  | Self balancing BST  | Hash Table
///                  | like Red-Black Tree |
///
///  search time     | log(n)              | O(1) -> Average
///                  |                     | O(n) -> Worst Case
///
///  Insertion time  | log(n) + Rebalance  | Same as search
///  Deletion time   | log(n) + Rebalance  | Same as search

/// Discussion: https://www.geeksforgeeks.org/map-vs-unordered_map-c/