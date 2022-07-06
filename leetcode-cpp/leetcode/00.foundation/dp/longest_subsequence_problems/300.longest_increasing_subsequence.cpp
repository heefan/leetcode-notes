//
// Created by litian on 14/6/22.
//

#include "common_inc.h"

class Solution300 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for(int i=1; i<n; i++) {
            for(int j=0; j<i; ++j) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

TEST_CASE("300.Longest Increasing Subsequence") {
    Solution300 sln;
    SECTION("case1") {
        vector<int> nums = {10,9,2,5,3,7,101,18};
        REQUIRE(sln.lengthOfLIS(nums) == 4);
    }

    SECTION("case2") {
        vector<int> nums = {0,1,0,3,2,3};
        REQUIRE(sln.lengthOfLIS(nums) == 4);
    }

    SECTION("case3") {
        vector<int> nums = {7,7,7,7,7,7,7};
        REQUIRE(sln.lengthOfLIS(nums) == 1);
    }
}