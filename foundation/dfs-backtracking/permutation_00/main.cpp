#define CATCH_CONFIG_MAIN
#include "Catch2/catch.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permutation(vector<int> & nums) {
        vector<vector<int>> res;
        vector<bool> isVisited;
        vector<int> path;

        dfs(nums, nums.size(), 0, path, isVisited, res);

        return res;
    }

    void dfs(vector<int>& nums,
             int length,
             int depth,
             vector<int> & path,
             vector<bool> & isVisited,
             vector<vector<int>> & res)
    {
        if(depth == length) {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < length; ++i) {
            if(!isVisited[i]) {
                path.push_back(nums[i]);
                isVisited[i] = true;

                dfs(nums, length, depth+1, path, isVisited, res);

                // backtracking
                isVisited[i] = false;
                path.erase(path.begin() + path.size() - 1);

            }
        }
    }
};

TEST_CASE("permutation example") {
    class Solution sln;

    SECTION("Given [1,2,3]") {
        vector<int> nums = {1,2,3};
        vector<vector<int>> res = sln.permutation(nums);
        vector<vector<int>> expect = {{1,2,3}, {1,3,2},
                                      {2,1,3}, {2,3,1},
                                      {3,1,2}, {3,2,1}};

        REQUIRE(equal(expect.begin(), expect.end(), res.begin()) == true);
    }
}
