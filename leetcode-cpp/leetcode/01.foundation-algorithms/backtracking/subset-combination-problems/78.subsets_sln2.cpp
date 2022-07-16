//
// Created by litian on 21/6/22.
//
#include "common_inc.h"

class Solution78_sln2 {
    vector<vector<int>> ans;
    vector<int> path;

public:
    vector<vector<int>> subsets(vector<int> & nums) {
        for (int i=0; i<=nums.size(); i++) {
            dfs(nums,i, 0) ;
        }

        return ans;
    }

private:
    void dfs(const vector<int>& nums, int depth, int start) {
        if(path.size() == depth) {
            ans.push_back(path);
            return;
        }

        for(int i=start; i<nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, depth, i+1);
            path.pop_back();
        }
    }
};


TEST_CASE("78. Subset solution 2 huahua/bfs") {
    Solution78_sln2 sln;

    SECTION("case1") {
        vector<int> nums = {1,2,3};
        vector<vector<int>> ans = sln.subsets(nums);
        vector<vector<int>> expect = {{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}};

        print2dVector(ans);

        REQUIRE(is2dVectorSame(ans, expect));
    }
}
