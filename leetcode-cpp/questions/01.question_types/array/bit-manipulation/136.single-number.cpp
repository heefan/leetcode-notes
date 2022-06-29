//
// Created by litian on 29/6/22.
//

#include "common_inc.h"

class Solution136 {
public:

    /*
     dry run:
     Bit manipulation:
     num ^ num = 0
     num ^ 0 = num
     numA ^ numsB ^ numsA =  numA ^ numsA ^ numB = numB

     let single = 0
     iterate the array element, and xor all the element, and the result is the single
        and  single = single ^ nums[i]

     */
    int singleNumber(vector<int>& nums) {
        int single = 0;
        for (int i=0; i<nums.size(); i++) {
            single = single ^ nums[i];
        }
        return single;
    }
};

TEST_CASE("136. Single Number"){
    Solution136 sln;

    SECTION("case1") {
        vector<int> nums = {2,2,1};
        int ans = sln.singleNumber(nums);
        REQUIRE(ans == 1);
    }

    SECTION("case2") {
        vector<int> nums = {4,1,2,1,2};
        int ans = sln.singleNumber(nums);
        REQUIRE(ans == 4);
    }

    SECTION("case2") {
        vector<int> nums = {1};
        int ans = sln.singleNumber(nums);
        REQUIRE(ans == 1);
    }
}


/*
up: 10259, down: 382
Given a non-empty array of integers nums,
 every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity
 and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1

Constraints:
1 <= nums.length <= 3 * 10^4
-3 * 10^4 <= nums[i] <= 3 * 10^4
Each element in the array appears twice except for one element which appears only once.
 */