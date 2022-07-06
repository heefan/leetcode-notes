//
// Created by litian on 30/6/22.
//

#include "common_inc.h"

class PrefixProduct {
public:
    vector<int> prefixProduct(const vector<int>& nums) {
        vector<int> prefix(nums.size() , 1);
        int product = 1;
        prefix[0] = 1;

        for(int i=1; i<prefix.size(); i++) {
            product = product * nums[i-1];
            prefix[i] = product;
        }

        return prefix;
    }
};

TEST_CASE("Prefix Product") {
    PrefixProduct sln;

    SECTION("case1") {
        vector<int> nums = {2,3,4,5};
        vector<int> ans = sln.prefixProduct(nums);
        vector<int> expect = {1,2,6,24};

        printVector(ans);
        REQUIRE(isVectorSame(ans, expect));
    }

    SECTION("case2") {
        vector<int> nums = {4,3,2,1,2};
        vector<int> ans = sln.prefixProduct(nums);
        vector<int> expect = {1,4,12,24,24};

        printVector(ans);
        REQUIRE(isVectorSame(ans, expect));
    }
}