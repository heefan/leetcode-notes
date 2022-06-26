//
// Created by litian on 25/6/22.
//

#include "common_inc.h"

class Permutation {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int> & nums) {
        vector<int> path;
        backtracking(nums, path, 0);
        return ans;
    }

private:
    void backtracking(vector<int> & nums, vector<int> & path, int depth) {
        if (depth > nums.size()) return;

        ans.push_back(path);
        for(int i=0; i<nums.size(); i++) {
            path.push_back(nums[i]);
            printVector(path);
            backtracking(nums, path, depth+1);
//            path.pop_back();
        }
    }
};

TEST_CASE("permutation test") {
    Permutation sln;

    SECTION("without backtracking") {
        vector<int> nums = {1,2};
        vector<vector<int>> ans = sln.permute(nums);

        print2dVector(ans);
    }
}