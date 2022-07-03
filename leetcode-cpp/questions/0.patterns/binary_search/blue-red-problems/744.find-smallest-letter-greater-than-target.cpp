//
// Created by litian on 3/7/22.
//

#include "common_inc.h"

class Solution744 {
public:

    /*
      dry run:  blue-red solution
              ["c","f","j"]  > "a"
          blue|----red------    return letter[0]

              ["c","f","j"]  > "c"
             blue | red---    return r

              ['c', 'd']         > 'z'
              ---blue---| red--  return letter[0]

              ['c', 'd']         > 'd'
              ---blue---| red--  return letter[0]

              letter[n-1] <= target ==> return letter[0]
     */
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.back() <= target) return letters[0];

        int l = -1;
        int r = letters.size();

        while( l+1 != r) {
            int m = l + (r-l) / 2;

            if(letters[m] <= target) {
                l = m;
            } else {
                r = m;
            }
        }

        return  letters[r];
    }
};

TEST_CASE("744. Find Smallest Letter Greater Than Target") {
    Solution744 sln;

    SECTION("case1") {
        vector<char> letters = {'c','f','j'};
        char ans = sln.nextGreatestLetter(letters, 'a');

        REQUIRE(ans == 'c');
    }

    SECTION("case2") {
        vector<char> letters = {'c','f','j'};
        char ans = sln.nextGreatestLetter(letters, 'c');

        REQUIRE(ans == 'f');
    }

    SECTION("case3") {
        vector<char> letters = {'c','f','j'};
        char ans = sln.nextGreatestLetter(letters, 'd');

        REQUIRE(ans == 'f');
    }
}

/*
 Given a characters array letters that is sorted in non-decreasing order and a character target,
 return the smallest character in the array that is larger than target.
 Note that the letters wrap around.
 For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.

 Example 1:
 Input: letters = ["c","f","j"], target = "a"
 Output: "c"

 Example 2:
 Input: letters = ["c","f","j"], target = "c"
 Output: "f"

 Example 3:
 Input: letters = ["c","f","j"], target = "d"
 Output: "f"
 */