//
// Created by siadev on 30/3/22.
//

/*
 * 81. Search in rotated sorted array II
 */
#include "catch.hpp"

using namespace  std;

class Solution81 {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while(l<=r) {
            int mid = l + (r-l)/2;
            if (target == nums[mid]) return true;

            if(nums[l] == nums[mid] and nums[mid] == nums[r]) {
                l++;
                r--;
            }

            if(nums[l] <= nums[mid]) {
                if(target >= nums[l] and target <= nums[mid]) {
                    r = mid -1;
                } else {
                    l = mid + 1;
                }
            }

            if(nums[mid] <= nums[r]) {
                if(target >= nums[mid] and target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid -1;
                }
            }
        }

        return false;
    }
};


TEST_CASE("81.search in rotated sorted array II") {
    SECTION("binary search") {
        Solution81 sln;
        vector<int> nums1 = {2,5,6,0,1,2};
        vector<int> nums2 = {1,0,1,1,1};   // 非常特殊的情况

        REQUIRE(sln.search(nums1, 3) == false);
        REQUIRE(sln.search(nums1, 2) == true);
        REQUIRE(sln.search(nums2, 0) == true);
    }
}




/*
*
* There is an integer array `nums` sorted in non-decreasing order (not necessarily
* with distinct values).
*
* Before being passed to your function, `nums` is rotated at an unknown pivot
* index `k` (`0 <= k < nums.length`) such that the resulting array is `[nums[k],
* nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (0-indexed).
* For example, `[0,1,2,4,4,4,5,6,6,7]` might be rotated at pivot index `5` and
* become `[4,5,6,6,7,0,1,2,4,4]`.
*
* Given the array `nums` after the rotation and an integer `target`, return
* `true`* if *`target`* is in *`nums`*, or *`false`* if it is not in *`nums`*.*
*
* You must decrease the overall operation steps as much as possible.
*
*
* Example 1:
* Input: nums = [2,5,6,0,0,1,2], target = 0
* Output: true
 *
* * Example 2: * * Input: nums = [2,5,6,0,0,1,2], target = 3
* Output: false
*
*
* Constraints:
*
* * `1 <= nums.length <= 5000`
* * `-10^4 <= nums[i] <= 10^4`
* * `nums` is guaranteed to be rotated at some pivot.
* * `-10^4 <= target <= 10^4`
*
*
* Follow up: This problem is similar to [Search in Rotated Sorted Array][1],
* but `nums` may contain duplicates. Would this affect the runtime complexity?
* How and why?
*
* [1] /problems/search-in-rotated-sorted-array/description/
*
*/
