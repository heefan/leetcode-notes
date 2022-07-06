//
// Created by litian on 6/7/22.
//

#include "common_inc.h"

class Solution378 {
public:

    // dry run :
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;

        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                pq.push(matrix[i][j]);

                if(pq.size() > k)
                    pq.pop();
            }
        }

        return pq.top();
    }
};

TEST_CASE("378. Kth Smallest Element in a Sorted Matrix") {
    Solution378 sln;

    SECTION("case1") {
        vector<vector<int>> matrix = {{1,5,9},
                                      {10,11,13},
                                      {12,13,15}};

        int ans = sln.kthSmallest(matrix, 8);

        REQUIRE(ans == 13);
    }

    SECTION("case2") {
        vector<vector<int>> matrix = {{-5}};
        int ans = sln.kthSmallest(matrix, 1);

        REQUIRE(ans == -5);
    }
}
