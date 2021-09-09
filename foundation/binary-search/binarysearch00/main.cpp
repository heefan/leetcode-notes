#define CATCH_CONFIG_MAIN
#include "Catch2/catch.hpp"
#include <vector>

using namespace  std;


// Important Notes:
// Prerequisite:
// 1. Sorted array
//
// Coding Skill Highlight:
// 1. calculate mid value.

class Solution {
public:
    bool binarySearch(const vector<int> & array, int target) {
        if(array.size() == 0) return false;

        int end = array.size() - 1;
        int begin = 0;


        while(end >= begin) {
            int mid = begin + (end - begin) / 2;
            if(target == array[mid]) return true;

            if(target > array[mid]) {
                begin = mid + 1;
            }

            if (target < array[mid]) {
                end = mid - 1;
            }
        }
        return false;
    }
};

TEST_CASE( "Binary Search Prototype Testing") {
    SECTION("Give a sorted array and target, to find out the target within O(n)") {

        Solution s = Solution();
        vector<int> input = {1,2,3};
        int target = 3;

        REQUIRE(s.binarySearch(input, 1) == true);
        REQUIRE(s.binarySearch(input, 2) == true);
        REQUIRE(s.binarySearch(input, 3) == true);
        REQUIRE(s.binarySearch(input, 4) == false);
    }
}