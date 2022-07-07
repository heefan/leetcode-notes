//
// Created by litian on 7/7/22.
//

#include "common_inc.h"

class Solution703 {
public:
    priority_queue<int, vector<int>, greater<int>> pq;  // min heap
    int k;

    Solution703(int k, vector<int>& nums): k(k) {
        pq = {nums.begin(), nums.end()};

        int n = nums.size();
        while( (n-k) > 0 and !pq.empty()) {
            pq.pop();
            n--;
        }
    }

    int add(int val) {
        if(pq.size() >= k) {
            if (pq.top() <= val) {
                pq.pop();
                pq.push(val);
            }
        } else {
            pq.push(val);
        }
        return pq.top();
    }
};

TEST_CASE("703. Kth Largest Element in a Stream") {

    SECTION("case1") {
        vector<int> nums = {4,5,8,2};
        Solution703 sln(3, nums);

        REQUIRE(4 == sln.add(4));
    }


    SECTION("case2") {
        vector<int> nums = {};
        Solution703 sln(1, nums);

        REQUIRE(-3 == sln.add(-3));
        REQUIRE(-2 == sln.add(-2));
        REQUIRE(-2 == sln.add(-4));
        REQUIRE(0 == sln.add(0));
        REQUIRE(4 == sln.add(4));
    }
}