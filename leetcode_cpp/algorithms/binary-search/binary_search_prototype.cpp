//
// Created by litian on 29/3/22.
//

#include <catch2/catch.hpp>
using namespace std;

int binarySearch(vector<int> & nums, int target) {
    int n = nums.size();
    if(n==0) return 0;

    int l = 0;
    int r = nums.size();

    while(l<=r) {
        int mid = l + (r-l)/2;

        if (target == nums[mid]) return mid;

        if(target <= nums[mid]) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    return -1;
}

TEST_CASE("algo: binary search") {
    SECTION("prototype") {
        vector<int> nums = {1,2,3,4,5};
        REQUIRE(binarySearch(nums, 1) == 0);
        REQUIRE(binarySearch(nums, 5) == 4);
        REQUIRE(binarySearch(nums, 3) == 2);
        REQUIRE(binarySearch(nums, 6) == -1);
    }
}
