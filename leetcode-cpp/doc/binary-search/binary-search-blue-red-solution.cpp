//
// Created by litian on 1/7/22.
//
#include "common_inc.h"

// The implementation is based on the following video,
// https://www.youtube.com/watch?v=JuDAqNyTG4g (Chinese)
//

class BinarySearchBuleRed {
public:
    // index of first number, nums[i] >= 5
    // [1,2,3,5,5,5,8,9]
    int search1(const vector<int> & nums, int t) {
        int l = -1;
        int r = nums.size();

        while(l+1 != r) {
            int m = l + (r-l)/2;

            if(nums[m] < t) {
                l = m;
            } else {
                r = m;
            }
        }

        return r;
    }


    // index of first number, nums[i] > 5
    // [1,2,3,5,5,5,8,9]
    int search2(const vector<int> & nums, int t) {
        int l = -1;
        int r = nums.size();

        while(l+1 != r) {
            int m = l + (r-l)/2;

            if(nums[m] <= t) {
                l = m;
            } else {
                r = m;
            }
        }

        return r;
    }

    // index of last number,  nums[i] < 5
    // [1,2,3,5,5,5,8,9]
    int search3(const vector<int> & nums, int t) {
        int l = -1;
        int r = nums.size();

        while(l+1 != r) {
            int m = l + (r-l)/2;

            if(nums[m] < t) {
                l = m;
            } else {
                r = m;
            }
        }

        return l;
    }

    // index of last number,  nums[i] <= 5
    // [1,2,3,5,5,5,8,9],
    int search4(const vector<int> & nums, int t) {
        int l = -1;
        int r = nums.size();

        while(l+1 != r) {
            int m = l + (r-l)/2;

            if(nums[m] <= 5) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
};

TEST_CASE("Binary Search Prototype") {
    BinarySearchBuleRed sln;

    SECTION("case1: index of the first number, where nums[i] >= 5") {
        vector<int> nums = {1,2,3,5,5,5,8,9};
        int ans =sln.search1(nums, 5);

        REQUIRE(ans == 3);  // nums[3]=5
    }

    SECTION("case2: index of the first number, where nums[i] > 5") {
        vector<int> nums = {1,2,3,5,5,5,8,9};
        int ans =sln.search2(nums, 5);

        REQUIRE(ans == 6);  // nums[6]=8
    }

    SECTION("case3: index of the last number, where nums[i] < 5") {
        vector<int> nums = {1,2,3,5,5,5,8,9};
        int ans =sln.search3(nums, 5);

        REQUIRE(ans == 2);   // nums[2]=3
    }

    SECTION("case4: index of the last number, where nums[i] <= 5") {
        vector<int> nums = {1,2,3,5,5,5,8,9};
        int ans =sln.search4(nums, 5);

        REQUIRE(ans == 5);   // nums[5]=5
    }
}