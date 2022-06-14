//
// Created by litian on 14/6/22.
//

#include "common_inc.h"
#include "vector_helper.h"

class Solution1042 {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n);

        for(auto &path: paths) {
            graph[path[0] - 1].push_back(path[1] - 1);
            graph[path[1] - 1].push_back(path[0] - 1);
        }

        vector<int> ans(n, -1);
        dfs(graph, ans, 0);

        return ans;
    }

    void dfs(vector<vector<int>>& g, vector<int>& ans, int k) {
        if (k == ans.size()) return;

        unordered_set<int> usedColor;
        for (auto adj: g[k]) {
            usedColor.insert(ans[adj]);
        }

        for(int i=1; i <=4; i++) {
            if(usedColor.count(i) == 0) {
                ans[k] = i;
                dfs (g, ans, k+1);
                break;
            }
        }
    }
};

TEST_CASE("1042. Flower Planting With No Adjacent") {
    Solution1042 sln;

    SECTION("case1") {
        vector<vector<int>> nums = {{1,2}, {2,3}, {3,1}};
        vector<int> ans = sln.gardenNoAdj(3, nums);

        REQUIRE(isVectorSame({1,2,3}, ans) == true);
    }

    SECTION("case2") {
        vector<vector<int>> nums = {{1,2}, {3,4}};
        vector<int> ans = sln.gardenNoAdj(4, nums);

        REQUIRE(isVectorSame({1,2,1,2}, ans) == true);
    }

    SECTION("case1") {
        vector<vector<int>> nums = {{1,2}, {2,3}, {3,4}, {4,1}, {1,3}, {2,4}};
        vector<int> ans = sln.gardenNoAdj(4, nums);

        REQUIRE(isVectorSame({1,2,3,4}, ans) == true);
    }
}

// dry run
// given: paths = [[1,2],[2,3],[3,1]]
//  adjacent list:
//    1:2
//    2:3
//    3:1
// Certainly, one garden could link with at most 2 others.

// graph, create an adjacent list, 2d array (start from 0-index)
//     graph[path[0]-1]: path[1]-1,


// 当garden为0时, 邻接garden是 [2]
// 我先要知道当前种花情况,  ans里边放了当前种花的情况,所以需要从里边取.
// 
