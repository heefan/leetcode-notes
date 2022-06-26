//
// Created by litian on 25/6/22.
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
        if (total == target) {
            cout << "push to answer: ";
            printVector(path);
            ans.push_back(path);
            return;
        }

        if (total > target) {
            cout << "over target: return" << endl;
            return;
        }

        for(int i=start; i<nums.size(); i++)  {
            cout << "==> checking: nums[" << i << "] = " << nums[i] << endl;
            cout << "current path: ";
            printVector(path);

            if (total + nums[i] < target) {
                path.push_back(nums[i]);
                backtracking(target, start, total+nums[i], path, nums);
            } else {
                return;
            }

            cout << "backtracking " << endl;
            path.pop_back();
            printVector(path);
            backtracking(target, start+1, total, path, nums);
        }
    }
};


TEST_CASE("39.Combination Sum") {
    Solution39 sln;

    SECTION("case1") {
        vector<int> nums = {2,3,6,7};
        int target = 7;

        vector<vector<int>> ans = sln.combinationSum(nums, target);
        vector<vector<int>> expect = {{2,2,3}, {7}};

        print2dVector(ans);
        REQUIRE(is2dVectorSame(ans, expect));
    }
}