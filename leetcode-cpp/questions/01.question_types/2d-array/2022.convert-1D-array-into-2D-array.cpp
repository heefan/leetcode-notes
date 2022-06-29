//
// Created by litian on 29/6/22.
//

#include "common_inc.h"

class Solution2022 {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m*n != original.size()) return {};

        vector<vector<int>> ans(m, vector<int>(n));

        int k=0;
        for(int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                ans[i][j] = original[k++];
            }
        }

        return ans;
    }
};

TEST_CASE("2022.Convert 1D Array Into 2D Array") {
    Solution2022 sln;

    SECTION("case1") {
        vector<int> nums = {1,2,3};
        vector<vector<int>> ans = sln.construct2DArray(nums, 1,3);
        vector<vector<int>> expect = {{1,2,3}};
        REQUIRE(is2dVectorSame(ans, expect));
    }

    SECTION("case2") {
        vector<int> nums = {1,2,3,4};
        vector<vector<int>> ans = sln.construct2DArray(nums, 4,1);
        vector<vector<int>> expect = {{1},{2},{3}, {4}};
        REQUIRE(is2dVectorSame(ans, expect));
    }
}