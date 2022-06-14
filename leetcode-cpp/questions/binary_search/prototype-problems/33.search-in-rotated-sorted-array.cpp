//
// Created by litian on 29/3/22.
//

/*
 * https://leetcode.com/problems/search-in-rotated-sorted-array/
 * 33. Search in Rotated Sorted Array
 */

#include "catch.hpp"
using namespace std;

class Solution33 {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while(l<=r) {
            int m = l + (r-l)/2;
            if(nums[m] == target) return m;

            if(nums[l] <= nums[m]) {
                if(target >= nums[l] and target <= nums[m]) {  // 理想情况    nums[l] < nums[target] < nums[m]
                    r = m-1;
                } else {
                    l = m+1;
                }
            } else {  // l -> mid  先升后降，  mid->r 升序
                if(target >= nums[m] and target <= nums[r]) {  // 理想情况   nums[m] < nums[target] < nums[r]
                    l =  m+1;
                } else {
                    r = m-1;   // 不理想情况下，至少我们知道 m-r一定是没有的。
                }
            }
        }
        return -1;
    }
};

TEST_CASE("33.search in rotated sorted array ") {
    SECTION("test") {
        vector<int> nums = {5,6,8,0,1,2,3,4};
        Solution33 sln;

        REQUIRE(sln.search(nums, 0) == 3);
        REQUIRE(sln.search(nums, 10) == -1);
    }
}

/*
https://leetcode.com/problems/search-in-rotated-sorted-array/
33. Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
 such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 For example,
 [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target,
 return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

 Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1

Constraints:
1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
 */
