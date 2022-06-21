//
// Created by litian on 16/6/22.
//

#include "common_inc.h"

class Solution90 {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;

        dfs(nums, tmp, 0);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int> tmp, int cur) {
        ans.push_back(tmp);

        // 这里的 set 是亮点, 目的是, 如果有使用过重复的元素, 起到过虑作用.
        // 比如, [1,2,2],
        // 当选择 1 时,
        //  1->2 (nums[1]), 下一条路径是 1->2->2
        //  1->2 (nums[2])
        //  显然 1->2 (nums[2]) 是要被忽略的. 如果set里边已经使用了该值一样的元素,则不再dfs下去.
        unordered_set<int> used;

        for(int i=cur; i<nums.size(); i++) {

            // 当i=cur时, 走完当前路径.
            if (!used.count(nums[i])) {
                tmp.push_back(nums[i]);
                dfs(nums, tmp, i+1);
                tmp.pop_back();
            }

            used.insert(nums[i]);
        }

        return;
    }
};

TEST_CASE("Solution90. Subset II") {
    Solution90 sln;

    SECTION("case1") {
        vector<int> nums = {1,2,2};
        vector<vector<int>> ans = sln.subsetsWithDup(nums);

//        REQUIRE("");
    }
}