//
// Created by litian on 15/6/22.
//

#include "common_inc.h"

class Solution128 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set({nums.begin(), nums.end()});

        int ans = 1;
        for(int i=0; i<nums.size(); i++) {
            if (set.count(nums[i] - 1) == 0) {
                int j = 1;
                int cnt = 1;
                while(set.count(nums[i]+j) != 0) {
                    cnt++;
                    j++;
                }
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};

TEST_CASE("128. Longest Consecutive Sequence") {
    Solution128 sln;

    SECTION("case1") {
        vector<int> nums = {100,4,200,1,3,2};
        int ans = sln.longestConsecutive(nums);

        REQUIRE(ans == 4);
    }

    SECTION("case2") {
        vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
        int ans = sln.longestConsecutive(nums);

        REQUIRE(ans == 9);
    }
}