
#include "catch.hpp"
#include <iostream>

using namespace std;

class Solution74 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int l = 0;
        int r = matrix.size() - 1;

        while(l <= r) {
            int mid_row = l + (r - l) / 2;

            if (target >= matrix[mid_row][0] and target <= matrix[mid_row][n-1]) {
                vector<int> nums = matrix[mid_row];
                return find(nums.begin(), nums.end(), target) == nums.end() ? false: true;
            }

            if(target < matrix[mid_row][0]) {
                r = mid_row - 1;
            }

            if(target > matrix[mid_row][n-1]) {
                l = mid_row + 1;
            }
        }

        return false;
    }
};

TEST_CASE("74.search a 2d matrix") {
    SECTION("binary-search") {
        vector<vector<int>> m1 = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
        vector<vector<int>> m2 = {{1,1}};

        Solution74 sln;

        REQUIRE(sln.searchMatrix(m1, 3) == true);
        REQUIRE(sln.searchMatrix(m1, 13) == false);
        REQUIRE(sln.searchMatrix(m1, 30) == true);
        REQUIRE(sln.searchMatrix(m1, 60) == true);
        REQUIRE(sln.searchMatrix(m2, 2) == false);
    }
}

/*
* Write an efficient algorithm that searches for a value `target` in an `m x n`
* integer matrix `matrix`. This matrix has the following properties:
*
* * Integers in each row are sorted from left to right.
* * The first integer of each row is greater than the last integer of the previous
*   row.
*
*
* Example 1:
* Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
* Output: true
*
* Example 2:
* Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
* Output: false
*
*
* Constraints:
*
* * `m == matrix.length`
* * `n == matrix[i].length`
* * `1 <= m, n <= 100`
* * `-104 <= matrix[i][j], target <= 104`
*
*/
