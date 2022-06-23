//
// Created by siadev on 23/6/22.
//

#include "common_inc.h"

class Solution77 {
    vector<vector<int>> ans;

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        dfs(n, k, comb, 1);
        return ans;
    }


    void dfs(int n, int k,  vector<int> & comb, int idx) {
        if(comb.size() == k) {
            ans.push_back(comb);
            return;
        }

        for(int i=idx; i<=n;  i++) {
            comb.push_back(i);
            dfs(n, k, comb, i+1);

            comb.pop_back();
        }
    }
};


TEST_CASE("77.Combinations") {
    Solution77 sln;

    SECTION("case1") {
        vector<vector<int>> ans = sln.combine(4, 2);
        vector<vector<int>> expect = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
        print2dVector(ans);

        REQUIRE(is2dVectorSame(ans, expect));
    }

    SECTION("case2") {
        vector<vector<int>> ans = sln.combine(1,1);
        vector<vector<int>> expect = {{1}};
        print2dVector(ans);

        REQUIRE(is2dVectorSame(ans, expect));
    }
}

// dry run (recursive tree)
// 1 -> 2
//   -> 3
//   -> 4

// 2 -> 1   => 1 selected, duplicated with [1,2]
// 2 -> 3
// 2 -> 4

// 3 -> 4

// 4  =>  X

//  O(n * 2^n)
