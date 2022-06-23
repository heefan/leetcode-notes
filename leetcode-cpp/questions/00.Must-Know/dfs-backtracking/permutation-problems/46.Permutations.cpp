//
// Created by siadev on 23/6/22.
//

#include "common_inc.h"

class Solution46 {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int> & nums) {
        vector<bool> visit(nums.size(), false);
        vector<int> path;
        dfs(nums, visit, path);

        return ans;
    }

    void dfs(vector<int> & nums, vector<bool> visit, vector<int> & path) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for(int i=0; i<visit.size(); i++) {
            if (!visit[i]) {
                path.push_back(nums[i]);
                visit[i] = true;
                dfs(nums, visit, path);

                path.pop_back();
                visit[i] = false;
            }
        }
    }
};

TEST_CASE("Solution46") {
    Solution46 sln;

    SECTION("case1") {
        vector<int> nums = {1,2,3};
        vector<vector<int>> expect = {{1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}};
        vector<vector<int>> ans =  sln.permute(nums);

        REQUIRE(is2dVectorSame(ans, expect));
    }

    SECTION("case2") {
        vector<int> nums = {0,1};
        vector<vector<int>> expect = {{0,1}, {1,0}};
        vector<vector<int>> ans =  sln.permute(nums);

        REQUIRE(is2dVectorSame(ans, expect));
    }

    SECTION("case3") {
        vector<int> nums = {1};
        vector<vector<int>> expect = {{1}};
        vector<vector<int>> ans =  sln.permute(nums);

        REQUIRE(is2dVectorSame(ans, expect));
    }
}