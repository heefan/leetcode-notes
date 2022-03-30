//
// Created by litian on 30/3/22.
//

// https://www.youtube.com/watch?v=JuDAqNyTG4g  讲解非常非常好
// 五点七边, 二分查找为什么总是写错？
// 主要是边界问题

// {1,2,3,5,5,5,8,9}
// q1. 找到第一个>=5的元素
// q2. 找到最后一个<5的元素
// q3. 找到第一个>5的元素
// q4. 找到最后一个<=5的元素


// 二分查找的方式计算根号2

#include <vector>
#include <catch2/catch.hpp>

using namespace std;

int findIndex_firstNumberGreaterThanOrEqual(vector<int>& nums, int target) {
    int l = -1;
    int r = nums.size();

    while(l+1 != r) {
        int m = (l+r)/2;

        if(nums[m] < target) {
            l = m;
        } else {
            r = m;
        }
    }

    return r;
}

int findLastNumberLessThan(vector<int>& nums, int target) {
    int l = -1;
    int r = nums.size();

    while(l+1 != r) {
        int m = (l+r)/2;

        if(nums[m] < target) {
            l = m;
        } else {
            r = m;
        }
    }

    return nums[l];
}

int findFirstNumberGreaterThan(vector<int> & nums, int target) {
    int l = -1;
    int r = nums.size();

    while(l+1 != r) {
        int m = (l+r)/2;

        if(nums[m] <= target) {
            l = m;
        } else {
            r = m;
        }
    }

    return nums[r];
}

int findIndex_lastNumberLessThanOrEqual(vector<int> & nums, int target) {
    int l = -1;
    int r = nums.size();

    while(l+1 != r) {
        int m = (l+r)/2;

        if(nums[m] <= target) {
            l = m;
        } else {
            r = m;
        }
    }

    return l;
}

TEST_CASE("五点七边") {
    SECTION("index: first number >= target") {
        vector<int> nums = {1,2,3,5,5,5,8,9};
        REQUIRE(findIndex_firstNumberGreaterThanOrEqual(nums, 5) == 3);
    }

    SECTION("last number < target") {
        vector<int> nums = {1,2,3,5,5,5,8,9};
        REQUIRE(findLastNumberLessThan(nums, 5) == 3);
    }

    SECTION("first number > target") {
        vector<int> nums = {1,2,3,5,5,5,8,9};
        REQUIRE(findFirstNumberGreaterThan(nums, 5) == 8);
    }

    SECTION("index: last number <= target") {
        vector<int> nums = {1,2,3,5,5,5,8,9};
        REQUIRE(findIndex_lastNumberLessThanOrEqual(nums, 5) == 5);
    }
}
