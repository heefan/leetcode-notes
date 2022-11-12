//
// Created by litian on 14/7/22.
//

//
// Created by litian on 13/7/22.
//
#include "common_inc.h"

class Solution442Prototype {
public:
    /*
      require:
        1. O(n), O(1)
        2. range 1-n
        3. appear 1 or 2 times

        1. (1)(2) in-place swap to place the numbers to the corresponding index.
            and iterate the array and find out the duplicate if nums[i] != i+1
    2. (1)(2) in-place map with index, if the index is marked as visited (set minus), we say it's duplicate.

    dry run:
    0 1 2 3 4 5 6 7
    4,3,2,7,8,2,3,1
    i,  nums[i],  j(nums[i]-1),  -nums[j]
    0    4        3               4,3,2,-7,8,2,3,1
    1    3        2               4,3,-2,-7,8,2,3,1
    2    2        1               4,-3,-2,-7,8,2,3,1
    3    7        6               4,-3,-2,-7,8,2,-3,1
    4    8        7               4,-3,-2,-7,8,2,-3,-1
    5    2        1               4,-3,-2,-7,8,2,-3,-1    in the case, nums[1]<0, meaning, the number 3 is visited, so it's duplicate.
    6    3        2               4,-3,-2,-7,8,2,-3,-1    in the case, nums[2]<0, meaning, the number 2 is visited, so it's duplicate.
    7    1        0               -4,-3,-2,-7,8,2,-3,-1
     *
     */
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            int j = abs(nums[i]) - 1;
            if(nums[j] < 0)
                ans.push_back(abs(nums[i]));

            nums[j] *= -1;
        }

        return ans;
    }
};


TEST_CASE("442. find all duplicates in an array: in place hash prototype") {
    Solution442Prototype sln;

    SECTION("case1") {
        vector<int> nums = {4,3,2,7,8,2,3,1};
        vector<int> expect = {2,3};
        vector<int> ans = sln.findDuplicates(nums);
        sort(ans.begin(), ans.end());

        REQUIRE(isVectorSame(ans, expect) == true);

    }

    SECTION("case2") {
        vector<int> nums = {2,1,1};
        vector<int> expect = {1};
        vector<int> ans = sln.findDuplicates(nums);
        sort(ans.begin(), ans.end());

        REQUIRE(isVectorSame(ans, expect) == true);
    }
}