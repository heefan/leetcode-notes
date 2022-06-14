//
// Created by litian on 13/3/22.
//
#include "catch.hpp"
#include <vector>
using namespace std;

int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for(auto& v: dig) {
        visited[v[0]][v[1]] = true;
    }

    int count = 0;

    for(auto& artifact: artifacts) {
        int r1 = artifact[0];
        int c1 = artifact[1];
        int r2 = artifact[2];
        int c2 = artifact[3];

        bool flag = true;

        for(int i=r1; i<=r2; i++) {
            for(int j=c1; j<=c2; j++) {
                if(!visited[i][j]) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) count++;
    }
    return count;
}

TEST_CASE("TestCases") {
    SECTION("case1") {
        vector<vector<int>> artifacts = {{0,0,0,0}, {0,1,1,1}};
        vector<vector<int>> dig = {{0,0}, {0,1}};
        int ans = digArtifacts(2, artifacts, dig);

        REQUIRE(ans == 1);

    }
}


