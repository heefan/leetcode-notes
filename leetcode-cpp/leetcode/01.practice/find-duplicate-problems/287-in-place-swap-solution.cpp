//
// Created by litian on 1/7/22.
//

#include "common_inc.h"

// Notes: The question does not allow modifying nums.
// I just practice on the in place swap solution


class Solution287_InPlaceSwap {
public:

    /*
    dry run:
    in place swap to sort the array (TC:(n), SC:O(1))
    The duplicate number can be found in the swap.

    0,1,2,3,4
    [1,3,4,2,2]
    1,4,3    swap(nums[1], nums[2])
    2,3,4
    (2) is already placed at nums[1], so it is duplicate
    nums[4] == nums[1] => true

    */
    int findDuplicate(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            // nums[1] != 2
            if (nums[i] != i+1) {
                // nums[1] == nums[2]
                if (nums[i] == nums[nums[i]-1]) {
                    return nums[i];
                } else {
                    swap(nums[i], nums[nums[i]-1]);
                    i--;
                }
            }
        }
    }
};

TEST_CASE("287. Find duplicates, In place swap solution") {
    Solution287_InPlaceSwap sln;

    SECTION("case1") {
        vector<int> nums = {1,2,3,2};
        int ans = sln.findDuplicate(nums);
        REQUIRE(ans == 2);
    }
}