//
// Created by LI Tian on 12/2/22.
//

//Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

#define  CATCH_MAIN_CONFIG
#include <catch2/catch.hpp>
#include "vector_helper.h"
#include <unordered_map>
#include <vector>

/// 评价：
/// 本题非常好，非常适合高端面试。

using namespace  std;
class Solution {
public:
    /// 本题如果没有给出限制，则可以直接使用 presum的公式。
    /// 但很明显，这是一个for-for循环，所以效率低的。
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int> presum = vector<int>(n+1);
        presum[0] = 0;
        for(int i=0;i<n;i++) {
            presum[i+1] = presum[i] + nums[i];
        }

        int ans=0;
        for(int i=0; i<n;i++) {
            for(int j=i; j<n; j++) {
                if(presum[j+1]-presum[i]==k) {
                    ans++;
                }
            }
        }
        return ans;
    }

    /// 如果给出限制条件 1 <= nums.length <= 2 * 10^4
    /// 说明就不能使用 O(n^2), 需要优化。优化的方向，依然基于前缀和方法，如何不用增加效率。
    /// 两数和的问题，第一反应就应该是 hashtable。
    int subarraySumOptimized(vector<int>& nums, int k) {
        int n=nums.size();
        int ans = 0;
        int presum=0;  //注意这里的presum并没有单独使用 vector
        unordered_map<int, int> mp;   // value, frequency
        mp[0]++;  // 在presum里边，第一个元素0是保留项。

        // nums = [1,1,1]
        // presum = [0,1,2,3,3,2]   k=2,   x=presum-2 => 2-2=0,  3-2=1
        // mp= {<0,1>, <1,1> <2,2> <3,2>  结果就是 次数相加

        // 本题变化是，presum通常使用数组表达，这里使用了 hashtable 来保存所有结果。
        // 因为presum 和是会有重复的，所以使用hashtable记录重复次数。
        for(int i=0; i<n; i++) {
            presum += nums[i];
            if(mp.count(presum-k)) {
                ans+=mp[presum-k];   // 表示不同情况的 次数和。
            }
            mp[presum]++;
        }
        return ans;
    }
};



TEST_CASE( "TestCases") {
    SECTION("Given nums=[1,1,1], k=2") {
        vector<int> nums = {1,1,1};
        int expect = 2;
        Solution sln = Solution();
        int ans1 = sln.subarraySum(nums, 2);
        int ans2 = sln.subarraySumOptimized(nums, 2);

        REQUIRE(ans1==2);
        REQUIRE(ans2==2);
    }

    SECTION("Given nums=[1,2,3], k=3") {
        vector<int> nums = {1,2,3};
        int expect = 2;
        Solution sln = Solution();
        int ans1 = sln.subarraySum(nums, 3);
        int ans2 = sln.subarraySumOptimized(nums, 3);

        REQUIRE(ans1==2);
        REQUIRE(ans2==2);
    }

    SECTION("Given nums=[1,0,1,1], k=3") {
        vector<int> nums = {1,0,1,1};
        int expect = 2;
        Solution sln = Solution();
        int ans1 = sln.subarraySum(nums, 3);
        int ans2 = sln.subarraySumOptimized(nums, 3);

        REQUIRE(ans1==1);
        REQUIRE(ans2==1);
    }
}
