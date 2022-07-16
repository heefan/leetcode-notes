//
// Created by litian on 7/7/22.
//

#include "common_inc.h"

class Solution373 {
public:

    struct compare{
        bool operator()(vector<int> &a, vector<int> &b){
            return a[0]+a[1] < b[0]+b[1];
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // <sums, <i,j>>
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        vector<vector<int>> ans;

        for (int i=0; i<nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (pq.size() < k) {
                    pq.push({nums1[i] + nums2[j]});
                } else if (pq.top()[0] + pq.top()[1] > nums1[i] + nums2[j]) {
                    pq.pop();
                    pq.push({nums1[i], nums2[j]});
                } else {
                    break;
                }
            }
        }

        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};

TEST_CASE("373. Find K Pairs with Smallest Sums") {
    Solution373 sln;

    SECTION("case1") {
        vector<int> nums1 = {1,7,11};
        vector<int> nums2 = {2,4,6};
        int k = 3;

        vector<vector<int>> expect = {{1,2},{1,4},{1,6}};
        auto ans = sln.kSmallestPairs(nums1, nums2, k);
        REQUIRE(is2dVectorSame(ans, ans));
    }

    SECTION("case2") {
        vector<int> nums1 = {1,1,2};
        vector<int> nums2 = {1,2,3};
        int k = 2;

        vector<vector<int>> expect = {{1,1}, {1,1}};
        auto ans = sln.kSmallestPairs(nums1, nums2, k);
        REQUIRE(is2dVectorSame(ans, ans));
    }
}


/*
* You are given two integer arrays `nums1` and `nums2` sorted in ascending
* order and an integer `k`.
*
* Define a pair `(u, v)` which consists of one element from the first array and
* one element from the second array.
*
* Return *the* `k` *pairs* `(u1, v1), (u2, v2), ..., (uk, vk)` *with the smallest
* sums*.
*
*
* Example 1:
*
* Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
* Output: [[1,2],[1,4],[1,6]]
* Explanation: The first 3 pairs are returned from the sequence:
* [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
*
* Example 2:
*
* Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
* Output: [[1,1],[1,1]]
* Explanation: The first 2 pairs are returned from the sequence:
* [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
*
* Example 3:
*
* Input: nums1 = [1,2], nums2 = [3], k = 3
* Output: [[1,3],[2,3]]
* Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
*
*
* Constraints:
*
* * `1 <= nums1.length, nums2.length <= 105`
* * `-109 <= nums1[i], nums2[i] <= 109`
* * `nums1` and `nums2` both are sorted in ascending order.
* * `1 <= k <= 104`
*
*/