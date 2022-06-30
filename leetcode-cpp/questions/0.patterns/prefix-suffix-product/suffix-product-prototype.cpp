//
// Created by litian on 30/6/22.
//

#include "common_inc.h"

class SuffixProduct {
public:
    vector<int> suffixProduct(const vector<int> & nums) {
        int n = nums.size();
        vector<int> suffixProduct(nums.size() , 0);
        int product = 1;
        suffixProduct[n-1] = 1;

        for(int i=n-2; i>=0; i--) {
            product = product * nums[i+1];
            suffixProduct[i] = product;
        }

        return suffixProduct;
    }
};

TEST_CASE("Suffix Product") {
    SuffixProduct sln;

    SECTION("case1") {
        vector<int> nums = {1,2,3,4};
        vector<int> ans1 = sln.suffixProduct(nums);
        vector<int> expect = {24, 12, 4, 1};
        printVector(ans1);

        REQUIRE(isVectorSame(ans1, expect));
    }

}
