//
// Created by litian on 21/6/22.
//

// #基础原型题
// Reference: Neetcode: https://www.youtube.com/watch?v=REOH22Xwdkk

#include "common_inc.h"

class Solution78_sln1 {
public:
    vector<int> path;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }


private:
    void dfs(int idx, const vector<int>& nums) {
        if (idx == nums.size()) {
            ans.push_back(path);
            return;
        }

        path.push_back(nums[idx]);
        dfs(idx+1, nums);
        path.pop_back();
        dfs(idx+1, nums);
    }
};

TEST_CASE("78. Subset, Solution 1: neetcode/official") {
    Solution78_sln1 sln;

    SECTION("case1") {
        vector<int> nums = {1,2,3};
        vector<vector<int>> ans = sln.subsets(nums);
        vector<vector<int>> expect = {{1,2,3}, {1,2}, {1,3}, {1}, {2,3}, {2}, {3}, {}};

        REQUIRE(is2dVectorSame(ans, expect));
    }

    SECTION("case2") {
        vector<int> nums = {0};
        vector<vector<int>> ans = sln.subsets(nums);
        vector<vector<int>> expect = {{0}, {}};
        print2dVector(ans);

        REQUIRE(is2dVectorSame(ans, expect));
    }
}