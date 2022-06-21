//
// Created by litian on 21/6/22.
//

#include "common_inc.h"

// neetcode solution:
// https://www.youtube.com/watch?v=Vn2v6ajA7U0
// note: I prefer the solution to official one.

class Solution90_sln1 {
    vector<int> path;
    vector<vector<int>> ans;

public:
    vector<vector<int>> subsetsWithDup(vector<int> & nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return ans;
    }

private:
    void dfs(int cur, const vector<int>& nums) {
        if (cur == nums.size()) {
            ans.push_back(path);
            return;
        }

        path.push_back(nums[cur]);
        dfs(cur+1, nums);
        path.pop_back();

        while(cur+1 < nums.size() and nums[cur] == nums[cur+1]) {
            cur++;
        }

        dfs(cur+1, nums);

    }
};

TEST_CASE("90. Subsets II Solution 1") {
    Solution90_sln1 sln;

    SECTION("case1") {
        vector<int> nums = {1,2,2};
        vector<vector<int>> ans = sln.subsetsWithDup(nums);
        vector<vector<int>> expect = {{1,2,2}, {1,2}, {1}, {2,2}, {2}, {}};

        print2dVector(ans);


        REQUIRE(is2dVectorSame(ans, expect));

    }
}