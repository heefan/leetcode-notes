//
// Created by litian on 29/6/22.
//

#include "common_inc.h"

/*
   dry run
   range: 1-n,  index: 0 ~ n-1
   nums[i] = i+1  (1~n)

   method 1: hashset
   put [1-n] to set   O(N)
   iterate the array, and remove the from set if exist.    O(N)
   the rest of the elements are the missing numbers
   TC: O(n),
   SC: O(n)

   Follow up: how to optimise SC to O(1)
   think about in place swap
   put the elements into the right index.
   iterate the array,  if nums[i] != i+1, meaning i+1 is the missing number.

   example,
   [4,3,2,7,8,2,3,1]
    1,2,3,4,2,3,7,8
    0,1,2,3,4,5,6,7
            - -
  */
class Solution448 {

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans = {};

        for(int i=0; i<n; i++) {
            if(nums[i] != i+1) {
                int j = nums[i] - 1;
                if (nums[j] != nums[i]) {
                    swap(nums[j], nums[i]);
                    i--;
                }
            }
        }

        for(int i=0; i<n; i++) {
            if (nums[i] != i+1) {
                ans.push_back(i+1);
            }
        }

        return ans;
    }

};

TEST_CASE("448. Find All Numbers Disappeared in an Array") {
    SECTION("case1") {


    }

    SECTION("case2") {

    }
}

/*
448.Find All Numbers Disappeared in an Array
 Given an array nums of n integers where nums[i] is in the range [1, n],
 return an array of all the integers in the range [1, n] that do not appear in nums.

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:
Input: nums = [1,1]
Output: [2]

Constraints:
  n == nums.length
  1 <= n <= 105
  1 <= nums[i] <= n
*/


