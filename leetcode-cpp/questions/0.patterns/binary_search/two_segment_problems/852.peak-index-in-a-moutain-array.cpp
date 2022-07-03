//
// Created by litian on 3/7/22.
//

#include "common_inc.h"

class Solution852 {
public:
    /*
     * dry run
     *  left side: arr[i-1] < arr[i]
     *  right side: arr[i-1] > arr[i]
     */
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;

        while(l<r) {
            int m = l + (r-l)/2;

            if(arr[m-1] < arr[m] and arr[m] > arr[m+1]) return m;

            if(arr[m] < arr[m-1]) {
                r = m;
            } else {
                l = m;
            }
        }

        return -1;
    }
};

TEST_CASE("857.Peak Index in a Mountain Array") {
    Solution852 sln;
    SECTION("case1") {
        vector<int> nums = {0,3,1};
        int ans = sln.peakIndexInMountainArray(nums);
        REQUIRE(ans == 1);
    }

    SECTION("case2") {
        vector<int> nums = {3,4,5,1};
        int ans = sln.peakIndexInMountainArray(nums);
        REQUIRE(ans == 2);
    }

    SECTION("case3"){
        vector<int> nums = {18,29,38,59,98,100,99,98,90};
        int ans = sln.peakIndexInMountainArray(nums);
        REQUIRE(ans == 5);
    }
}