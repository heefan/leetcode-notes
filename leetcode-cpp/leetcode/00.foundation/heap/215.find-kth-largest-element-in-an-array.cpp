//
// Created by litian on 6/7/22.
//

#include "common_inc.h"

class Solution215 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        for(int i=1; i<k; i++) {
            pq.pop();
        }

        return pq.top();
    }
};

TEST_CASE("251.The Kth Largest Number") {
    Solution215 sln;

    SECTION("case1") {
        vector<int> nums = {3,2,1,5,6,4};
        int ans = sln.findKthLargest(nums, 2);   // 1,2,3,4,5,6

        REQUIRE(ans == 5);
    }

    SECTION("case2") {
        vector<int> nums = {3,2,3,1,2,4,5,5,6};
        int ans = sln.findKthLargest(nums, 4);   // 1,2,3,4,5,6

        REQUIRE(ans == 4);
    }
}