#define CATCH_CONFIG_MAIN
#include "Catch2/catch.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countGoodSubstrings(const string & s) {
        int index = 0;
        int offset = 0;
        int ret = 0;
        unordered_map<char, int> hashtable;

        while(index <= s.size()) {


            if(index + offset > s.size()) {
                break;
            }

            if (offset == 3) {
                if(hashtable.size() == 3) {
                    ret++;
                }
                offset = 0;
                index++;
                hashtable.clear();
            }

            int currentIndex = index + offset;
            char currentValue = s[currentIndex];

            unordered_map<char, int>::const_iterator got = hashtable.find(currentValue);

            if (got == hashtable.end()) {
                hashtable.insert({currentValue, currentIndex});
            }

            offset++;
        }

        return ret;
    }
};


TEST_CASE("167. Two Sum II - Input array is sorted") {
    Solution sln = Solution();

    SECTION("given xyxzaz, it should be 1") {
        int ret = sln.countGoodSubstrings("xyzzaz");

        REQUIRE(ret == 1);
    }

    SECTION("given aababcabc, it should be 4") {
        int ret = sln.countGoodSubstrings("aababcabc");

        REQUIRE(ret == 4);
    }
}




