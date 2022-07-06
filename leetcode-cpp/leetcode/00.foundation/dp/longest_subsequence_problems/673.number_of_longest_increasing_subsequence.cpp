//
// Created by litian on 14/6/22.
//

#include "common_inc.h"

class Solution673 {
public:
    int findNumberOfLIS(vector<int>& nums) {


        return 1;
    }
};

TEST_CASE("673.Number of longest Increasing Subsequence") {
    Solution673 sln = Solution673();

    SECTION("Case1") {
        vector<int> nums = {2,2,2,2,2};
        REQUIRE(sln.findNumberOfLIS(nums) == 5);
    }

    SECTION("Case2") {
        vector<int> nums = {1,3,5,4,7};
        REQUIRE(sln.findNumberOfLIS(nums) == 2);
    }
}
