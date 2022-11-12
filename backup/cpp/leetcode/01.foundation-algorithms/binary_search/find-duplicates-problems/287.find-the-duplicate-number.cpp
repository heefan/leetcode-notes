//
// Created by litian on 31/3/22.
//

#include "common_inc.h"

using namespace std;

class Solution287 {
public:
    int findDuplicate(vector<int>& nums) {
        int l = -1;
        int r =  nums.size();

        while(l+1!=r) {
            int mid = (l+r)/2;

            int count = 0;
            for(auto d: nums) {
                if(d <= mid) count++;
            }

            if(count > mid) {
                r = mid;
            } else {
                l = mid;
            }
        }

        return r;
    }
};

TEST_CASE("287.find the duplicate number") {
    SECTION("binary-search") {
        vector<int> nums1 = {1,3,4,2,2};
        vector<int> nums2 = {3,1,3,4,2};
        Solution287 sln;

        REQUIRE(sln.findDuplicate(nums1) == 2);
        REQUIRE(sln.findDuplicate(nums2) == 3);
    }
}

/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3


Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
*/

