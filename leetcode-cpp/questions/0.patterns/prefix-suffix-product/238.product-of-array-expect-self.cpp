//
// Created by litian on 30/6/22.
//

#include "common_inc.h"

class Solution238 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix = prefixProduct(nums);
        vector<int> suffix = suffixProduct(nums);

        printVector(prefix);
        printVector(suffix);

        vector<int> ans;

        for (int i=0; i<nums.size(); i++) {
            int p = prefix[i];
            int q = suffix[i];

            ans.push_back(p * q);
        }

        return ans;
    }

private:
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

TEST_CASE("238. Product of Array Expect Self") {
    Solution238 sln;

    SECTION("case1") {
        vector<int> nums = {1,2,3,4};
        vector<int> expect = {24, 12, 8, 6};
        vector<int> ans = sln.productExceptSelf(nums);
        REQUIRE(isVectorSame(ans, expect));
    }

    SECTION("case2") {
        vector<int> nums = {-1,1,0,-3,3};
        vector<int> expect = {0,0,9,0,0};
        vector<int> ans = sln.productExceptSelf(nums);
        REQUIRE(isVectorSame(ans, expect));
    }

    SECTION("case3") {
        vector<int> nums = {4,3,2,1,2};
        vector<int> expect = {12,16,24,48,24};
        vector<int> ans = sln.productExceptSelf(nums);
        REQUIRE(isVectorSame(ans, expect));
    }
}