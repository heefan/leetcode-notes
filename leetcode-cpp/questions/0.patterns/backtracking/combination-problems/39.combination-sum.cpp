//
// Created by litian on 26/6/22.
//

#include "common_inc.h"

class Solution39 {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        backtracking(target, 0, 0, path, candidates);
        return ans;
    }

private:
    void backtracking(int target, int start, int total, vector<int>& path, const vector<int> & nums) {
        if(total > target) { return; }
        if(total == target) {
            ans.push_back(path);
            return;
        }

        for(int i=start; i<nums.size(); i++)  {
            path.push_back(nums[i]);
            total += nums[i];
            backtracking(target, i, total, path, nums);
            path.pop_back();
            total -= nums[i];
        }
    }
};


TEST_CASE("39.Combination Sum") {
    Solution39 sln;

    SECTION("case1") {
        vector<int> nums = {2,3,5};
        int target = 8;
        vector<vector<int>> ans = sln.combinationSum(nums, target);
        print2dVector(ans);
    }
}