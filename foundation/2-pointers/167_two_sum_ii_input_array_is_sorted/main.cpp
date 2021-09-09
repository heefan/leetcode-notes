#define CATCH_CONFIG_MAIN
#include "Catch2/catch.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool AssertVector(const vector<int> & v1, const vector<int> & v2) {
    return isEqual = v1 == v2;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        vector<int> result = {};
        while( left <= right) {
            int leftValue = numbers[left];
            int rightValue = numbers[right];

            if(rightValue + leftValue == target) {
                result.push_back(left + 1);
                result.push_back(right + 1);
                break;
            }

            if(rightValue > target) {
                right --;
                continue;
            }

            if (rightValue + leftValue > target) {
                right --;
                continue;
            }

            if (rightValue + leftValue < target) {
                left ++;
                continue;
            }
        }

        return result;
    }
};

TEST_CASE("167. Two Sum II - Input array is sorted") {
    Solution sln = Solution();

    SECTION("it should be {1,2} due to numbers[0] + numbers[1] = 9 ") {
        vector<int> numbers = {2,7,11,15};
        int target = 9;
        vector<int> expect = {1, 2};

        REQUIRE(AssertVector(sln.twoSum(numbers, target), expect) == true);
    }

    SECTION("") {
        vector<int> numbers = {2,3,4};
        int target = 6;
        vector<int> expect = {1, 3};

        bool isSame = AssertVector(sln.twoSum(numbers, target), expect);

        REQUIRE( isSame == true);
        REQUIRE(AssertVector(sln.twoSum(numbers, target), expect) == true);
    }

    SECTION("") {
        vector<int> numbers = {-1, 0};
        int target = -1;
        vector<int> expect = {1, 2};

        REQUIRE(AssertVector(sln.twoSum(numbers, target), expect) == true);
    }

    SECTION("") {
        vector<int> numbers = {1, 3, 5, 7, 11};
        int target = 10;
        vector<int> expect = {2, 4};

        REQUIRE(AssertVector(sln.twoSum(numbers, target), expect) == true);
    }
}

