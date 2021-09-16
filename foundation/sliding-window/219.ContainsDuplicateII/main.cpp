#define CATCH_CONFIG_MAIN
#include "Catch2/catch.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool ret = false;
        unordered_map<int, int> window;

        for(int i = 0; i < nums.size(); ++i) {
            unordered_map<int,int>::const_iterator got = window.find(nums[i]);
            if(got != window.end()) {
                int index = window.at(nums[i]);
                if (abs(index - i) <= k) {
                    return true;
                } else {
                    window.at(nums[i]) = i;
                }

            } else {
                window.insert({nums[i], i});
            }
        }

        return ret;
    }
};


TEST_CASE("leetcode.219") {
    class Solution sln;

    SECTION("when give [1,0,1,1], k=1, it should be true") {
        vector<int> testData = {1, 0, 1, 1};
        bool ret = sln.containsNearbyDuplicate(testData, 1);

        REQUIRE(ret == true);

    }

    SECTION("when give [1], k=1, it should be false") {
        vector<int> testData = {1};
        bool ret = sln.containsNearbyDuplicate(testData, 1);

        REQUIRE(ret == false);

    }

    SECTION("when give [99, 99], k=2, it should be false") {
        vector<int> testData = {99, 99};
        bool ret = sln.containsNearbyDuplicate(testData, 2);

        REQUIRE(ret == true);
    }



    SECTION("when give [1,2,3,1], k=3, it should be false") {
        vector<int> testData = {1, 2, 3, 1};
        bool ret = sln.containsNearbyDuplicate(testData, 3);

        REQUIRE(ret == true);

    }

    SECTION("when give [1,2,3,1,2,3], k=2, it should be false") {
        vector<int> testData = {1, 2, 3, 1, 2, 3};
        bool ret = sln.containsNearbyDuplicate(testData, 2);

        REQUIRE(ret == false);
    }

    SECTION("when give [1,2,3,1,2,3], k=2, it should be false") {
        vector<int> testData = {1, 2, 3};
        bool ret = sln.containsNearbyDuplicate(testData, 3);

        REQUIRE(ret == false);
    }
}