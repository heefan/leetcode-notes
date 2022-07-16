//
// Created by litian on 14/7/22.
//

#include "common_inc.h"

class Solution73 {
public:
    /*
     *  There is no special algorithm for the question.
     *  Just Code It.
     *
     *  1. try not reset the rows and col, so we should mark it first and then set 0s.
     *  2. we use 1 row and 1 col to mark
     *  3. however, after update 1st row/col, we will not know the original status.
     *  4. so we need to check 1st row/col before scan.
     *
     */
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool isFirstRowZeros = false;
        bool isFirstColZeros = false;

        for(int i=0; i<m; i++) {
            if(matrix[0][i] == 0) {
                isFirstColZeros = true;
                break;
            }
        }

        for(int i=0; i<n; i++) {
            if(matrix[i][0] == 0)  {
                isFirstColZeros = true;
                break;
            }
        }

        // mark the row and col
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // update matrix
        for(int i=1; i<m; i++) {
            if(matrix[i][0] == 0) {
                for (int j=1; j<n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j=1; j<n; j++) {
            if(matrix[0][j] == 0) {
                for(int i=1; i<m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (isFirstColZeros)  {
            for(int j=0; j<n; j++)
                matrix[0][j] = 0;
        }

        if (isFirstColZeros)  {
            for(int i=0; i<m; i++)
                matrix[i][0] = 0;
        }
    }
};

TEST_CASE("73. Set Matrix Zeroes") {
    Solution73 sln;

    SECTION("") {
        vector<vector<int>> nums = {{1,1,1}, {1,0,1}, {1,1,1}};
        vector<vector<int>> expect = {{1,0,1}, {0,0,0}, {1,0,1}};
        sln.setZeroes(nums);

        REQUIRE(is2dVectorSame(nums, expect));
    }
}