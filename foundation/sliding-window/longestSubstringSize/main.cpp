#define CATCH_CONFIG_MAIN
#include "Catch2/catch.hpp"
#include <string>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {




        return 0;
    }

};

TEST_CASE("Leetcode3") {

    SECTION("the output must be the longest substring size") {
        Solution sln = Solution();

        REQUIRE(sln.lengthOfLongestSubstring("abcabcbb") == 3);
        REQUIRE(sln.lengthOfLongestSubstring("pwwkew") == 3);
        REQUIRE(sln.lengthOfLongestSubstring("bbbbbb") == 1);
    }
}