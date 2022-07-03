//
// Created by litian on 1/7/22.
//

#include "common_inc.h"

// blue-red-solution
class Solution704 {
public:
    int search(vector<int>& nums, int target) {
        int l = -1, r = nums.size();

        while(l+1 != r) {
            int m = l + (r-l)/2;

            if (nums[m] == target) { return m;}
            if(nums[m] < target) {
                l = m;
            } else {
                r = m;
            }
        }

        return -1;
    }
};

TEST_CASE("704.Binary Search") {
    Solution704 sln;

    SECTION("case1") {
        vector<int>  nums = {-1,0,3,5,9,12};
        int ans1 = sln.search(nums, 9);
        int ans2 = sln.search(nums, 2);

        REQUIRE(ans1 == 4);
        REQUIRE(ans2 == -1);
    }
}


/*
 Given an array of integers nums which is sorted in ascending order,
 and an integer target, write a function to search target in nums.
 If target exists, then return its index. Otherwise, return -1.
 You must write an algorithm with O(log n) runtime complexity.

 Example 1:
 Input: nums = [-1,0,3,5,9,12], target = 9
 Output: 4
 Explanation: 9 exists in nums and its index is 4

 Example 2:
 Input: nums = [-1,0,3,5,9,12], target = 2
 Output: -1
 Explanation: 2 does not exist in nums so return -1
 */