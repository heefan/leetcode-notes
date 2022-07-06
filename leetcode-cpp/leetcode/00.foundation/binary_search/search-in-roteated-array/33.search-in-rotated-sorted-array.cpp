//
// Created by litian on 29/3/22.
//

#include "common_inc.h"

/*
 * dry run:
 *
 *  what's the condition that I can confirm?
 *
 *  nums[l] < nums[m] < nums[r]   (target)
 *
 *  4,5,6,[0],1,2,3,  nums[l] > nums[m]
 *  nums[l]  < target  =>  left
 *  nums[
 *
 *
 */
class Solution33 {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() -1;

        while(l<=r) {
            int m = l + (r-l)/2;
            if(nums[m] == target) return m;

            if(nums[0] <= nums[m]) { // [0,m] is sorted
                if(nums[0] <= target and target < nums[m]) {  // 0 <= target < m
                    r = m-1;
                } else {
                    l = m+1;
                }
            } else {   // (m ~ end) is sorted
                if(nums[m] < target and target <= nums[r]) {
                    l =  m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};

TEST_CASE("33.search in rotated sorted array ") {
    Solution33 sln;
    SECTION("case1") {
        vector<int> nums = {5,6,8,0,1,2,3,4};
        REQUIRE(sln.search(nums, 0) == 3);
    }

    SECTION("case2") {
        vector<int> nums = {1};
        REQUIRE(sln.search(nums, 1) == 0);
    }

    SECTION("case3") {
        vector<int> nums = {1};
        REQUIRE(sln.search(nums, 0) == -1);
    }

    SECTION("case4") {
        vector<int> nums = {3,1};
        REQUIRE(sln.search(nums, 1) == 1);
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
