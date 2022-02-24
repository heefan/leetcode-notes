//
// Created by LI Tian on 4/2/22.
//

#include <catch2/catch.hpp>
#include "vector_helper.h"

using namespace std;

/// 知识点： 前缀和
/// preSum[i] 就是 nums[0..i-1] 的和
int presum(vector<int> & nums, int i, int j) {
    int n = nums.size();
    vector<int> presum(n+1);
    presum[0]=0;
    for(int i=0; i<n; ++i) {
        presum[i+1] = presum[i]+nums[i];
    }

    printVector(presum);

    return presum[j+1]-presum[i];
}


//前缀和基础性质：对于nums数组，如果要求i...j的元素和，则 presum[j+1]-presum[i]"
TEST_CASE( "1.fundamental") {
    SECTION("Given nums=[1,2,3,4,5,6], find out the sum between 1 to 3") {

        vector<int> nums = {1,2,3,4,5};
        int ans = presum(nums, 1, 3);
        int expect = 9;

        REQUIRE(ans==9);
    }
}

