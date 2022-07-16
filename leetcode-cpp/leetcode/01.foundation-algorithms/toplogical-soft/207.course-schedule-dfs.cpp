//
// Created by litian on 11/7/22.
//


#include "common_inc.h"

class Solution207_dfs {
private:
    vector<vector<int>> graph;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u) {
        visited[u] = 1;
        for (int v: graph[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& edge: prerequisites) {
            int start = edge[0];
            int end = edge[1];
            graph[end].push_back(start);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};

TEST_CASE("207_dfs. Course Schedule") {
    Solution207_dfs sln;

    SECTION("case1") {
        int numCourses = 2;
        vector<vector<int>> prerequisites = {{1,0}};

        REQUIRE( true == sln.canFinish(2, prerequisites));
    }

//    SECTION("case2") {
//        int numCourses = 2;
//        vector<vector<int>> prerequisites = {{1,0}, {0,1}};
//
//        REQUIRE( false == sln.canFinish(2, prerequisites));
//    }
}
