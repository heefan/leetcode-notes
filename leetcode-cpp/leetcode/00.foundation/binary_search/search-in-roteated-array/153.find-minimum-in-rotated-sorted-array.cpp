//
// Created by litian on 4/7/22.
//

#include "common_inc.h"

class Solution153 {
public:
    /*
     * dry run:
     * two cases,
     *  [3,4,5,1,2],
     *    nums[l] < nums[m] > nums[r]:  right side
     *    nums[l] < nums[m] < nums[r]:  left side
     *    nums[l] > nums[m] > nums[r]:  no such case
     *    nums[l] > nums[m] < nums[r]:  no such case
     *
     * if nums[m] > nums[r], the min number must in right side
     *    l = m + 1, the min definitely cannot be nums[m]
     * if nums[m] == nums[r],  no such case
     * if nums[m] < nums[r], the min number must in left side
     *    r = m,  the min could be nums[m]
     *
     *  left    right    mid    cond                result
     *   0        4       2     nums[2] > nums[4]   l =
     *
     *  base condition:
     *  if nums[m]
     *
     */

    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while( l < r) {
            int m = l + (r-l)/2;

            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return nums[l];
    }
};

TEST_CASE("153. Find Minimum in Rotated Sorted Array") {
    Solution153 sln;

    SECTION("case1") {
        vector<int> nums = {3,4,5,1,2};
        int ans = sln.findMin(nums);
        REQUIRE(ans == 1);
    }

    SECTION("case2") {
        vector<int> nums = {4,5,6,7,0,1,2};
        int ans = sln.findMin(nums);
        REQUIRE(ans == 0);
    }

    SECTION("case3") {
        vector<int> nums = {11,13,15,17};
        int ans = sln.findMin(nums);
        REQUIRE(ans == 11);
    }

    SECTION("case4") {
        vector<int> nums = {1};
        int ans = sln.findMin(nums);
        REQUIRE(ans == 1);
    }
}


/*
 *  Find min value in a roated sorted array
 *  nums = [3,4,5,1,2]
 */