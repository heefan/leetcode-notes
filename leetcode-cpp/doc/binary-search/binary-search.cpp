//
// Created by litian on 29/3/22.
//

#include "common_inc.h"

class BinarySearch {
public:
    int preciseFind(const vector<int> & nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while( l<=r ) {
            int m = l + (r-l)/2;

            if (target == nums[m]) return m;

            if(target <= nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return -1;
    }

    int fuzzFind_l(const vector<int> & nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l<r) {
            int m = l + (r-l)/2;

            if(nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l;
    }

    int fuzzFind_r(const vector<int> & nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l<r) {
            int m = l + (r-l)/2;

            if(nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l;
    }
};


TEST_CASE("prototype: binary search") {
    BinarySearch sln;

    SECTION("case1: precise find") {
        vector<int> nums = {1,2,3,4,5};
        REQUIRE(sln.preciseFind(nums, 1) == 0);
        REQUIRE(sln.preciseFind(nums, 0) == -1);
    }

    SECTION("case2: fuzz find") {
        vector<int> nums = {1,1,2,2,2,6,7};

    }
}
