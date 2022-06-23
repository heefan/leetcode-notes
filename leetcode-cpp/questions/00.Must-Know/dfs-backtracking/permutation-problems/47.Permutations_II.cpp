//
// Created by siadev on 23/6/22.
//

#include "common_inc.h"

class Solution47 {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        vector<bool> visit(nums.size(), false);

        dfs(nums, path, visit);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int> & path, vector<bool> & visit) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i=0; i<visit.size(); i++) {
            if (!visit[i]) {
                if(i>0 and nums[i] == nums[i-1] and !visit[i-1] )  {
                    continue;
                }

                path.push_back(nums[i]);
                visit[i] = true;
                dfs(nums, path, visit);
                path.pop_back();
                visit[i] = false;
            }
        }
    }
};

TEST_CASE("Solution47") {
    Solution47 sln;

    SECTION("case1") {
        vector<int> nums = {1,2,3};
        vector<vector<int>> expect = {{1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}};
        vector<vector<int>> ans = sln.permuteUnique(nums);

        print2dVector(ans);

        REQUIRE(is2dVectorSame(expect, ans));
    }

    SECTION("case2") {
        vector<int> nums = {1,1,2};
        vector<vector<int>> expect = {{1,1,2}, {1,2,1}, {2,1,1}};
        vector<vector<int>> ans = sln.permuteUnique(nums);

        print2dVector(ans);

        REQUIRE(is2dVectorSame(expect, ans));
    }
}

// recursive tree
//  1->1->2 => [1,1,2]   nums[i-1] == nums[i] and visited[i-1] == false --> valid
//      <-
//     2->1  => [1,2,1]
//   <-   <-
// next one is 1 (we don't use it since duplicate, nums[i-1] == nums[i]
//  ignore the second 1
//  2 -> 1 -> 1
//        <-     nums[i-1] == nums[i]
//