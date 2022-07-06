//
// Created by litian on 29/6/22.
//

#include "common_inc.h"

// dry run
// method 1:
// sort the array: n(logn)
// iterate the array,  if nums[i] == nums[i-1], meaning duplicate and return true.
// TC: O(logN + N)
// SC: O(1)

// method 2:
// use hash set: TC: O(1), SC: O(n)
// iterate the array, and check if the number in the set,  TC: O(N)
// if yes, then return true,
// if not, insert into the set.
// TC: O(N)
// SC: O(n)

class Solution217 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for (int i=0; i<nums.size(); i++) {
            if (set.count(nums[i]) == 0) {
                set.insert(nums[i]);
            } else {
                return true;
            }
        }

        return false;
    }
};


TEST_CASE("217.Contains Duplicate") {
    Solution217 sln;

    SECTION("case1") {
        vector<int> nums = {1,2,3,1};
        bool ans = sln.containsDuplicate(nums);
        REQUIRE(ans == true);
    }

    SECTION("case2") {
        vector<int> nums = {1,2,3,4};
        bool ans = sln.containsDuplicate(nums);
        REQUIRE(ans == false);

    }

    SECTION("case3") {
        vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
        bool ans = sln.containsDuplicate(nums);
        REQUIRE(ans == true);
    }
}


/*
Given an integer array nums, return true if any value appears at least twice in the array,
 and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
 */