//
// Created by litian on 10/7/22.
//

#include "common_inc.h"

class Solution207_bfs {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. build graph
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses,0);

        for (int i=0; i<prerequisites.size(); ++i) {
            int start = prerequisites[i][0];
            int end = prerequisites[i][1];
            degree[start]++;   // calcualte in-degree
            graph[end].push_back(start);
        }

        queue<int> q;

        // 2. push 0 in degree to queue
        for (int i=0; i<numCourses; i++) {
            if (degree[i] == 0)
                q.push(i);
        }

        // 3. topological sort
        int count = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            count++;

            for(auto i: graph[cur]) {
                degree[i]--;
                if(degree[i] == 0) {
                    q.push(i);
                }
            }
        }

        return count == numCourses;
    }
};

TEST_CASE("207. Course Schedule") {
    Solution207_bfs sln;

    SECTION("case1") {
        int numCourses = 2;
        vector<vector<int>> prerequisites = {{1,0}};

        REQUIRE( true == sln.canFinish(2, prerequisites));
    }

    SECTION("case2") {
        int numCourses = 2;
        vector<vector<int>> prerequisites = {{1,0}, {0,1}};

        REQUIRE( false == sln.canFinish(2, prerequisites));
    }
}

