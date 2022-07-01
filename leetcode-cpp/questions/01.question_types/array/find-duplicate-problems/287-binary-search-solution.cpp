//
// Created by litian on 1/7/22.
//

#include "common_inc.h"

class Solution287_BinarySearch {
public:

    /*
     Restriction:  not modify array, and O(1) SC

     dry run:
     i    0,1,2,3,4     hole
     num [1,3,4,2,2]    pigeon
     cnt  0,1,3,4,5     how many cases that holes are enough to pigeon
          by right, cnt[i] <= i, meaning, I have more holes to pigeons
                 if cnt[i] == i,  meaning, each hole has a pigeon
                 if cnt[i] > i,  meaning, I do not have enough holes for pigeons.
                      It must have duplicate number.
     if nums[i] > i, meaning, the duplicate happens and the rest of number must have duplicates as well.
     so I should search left side.  r = mid - 1;

    */
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1;

        while(low < high) {
            int mid = low + (high-low)/2;
            int count = 0;
            for (int i=0; i<nums.size(); i++) {
                if (nums[i] <= mid) {
                    count++;
                }
            }

            if (count > mid)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

TEST_CASE("287. Find duplicates, Binary Search solution") {
    Solution287_BinarySearch sln;

    SECTION("case1") {
        vector<int> nums = {1,2,3,2};
        int ans = sln.findDuplicate(nums);
        REQUIRE(ans == 2);
    }
}
