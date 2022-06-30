//
// Created by litian on 30/6/22.
//

#include "common_inc.h"

class Preproduct {
public:
    vector<int> preproduct_1(vector<int> nums) {
        vector<int> preproduct(nums.size() + 1, 1);
        preproduct[0] = 1;

        for(int i=1; i<preproduct.size(); i++) {
            preproduct[i] = nums[i-1] * preproduct[i-1];
        }

        return {preproduct.begin()+1, preproduct.end()};
    }

    vector<int> preproduct_2(vector<int> nums) {
        vector<int> preproduct(nums.size() , 1);
        int product = 1;

        for(int i=0; i<preproduct.size(); i++) {
            product = product * nums[i];
            preproduct[i] = product;
        }

        return preproduct;
    }
};

TEST_CASE("PreProduct") {
    Preproduct sln;

    SECTION("case1") {
        vector<int> nums = {1,2,3};
        vector<int> ans1 = sln.preproduct_1(nums);
        vector<int> ans2 = sln.preproduct_2(nums);

        printVector(ans1);
        printVector(ans2);
    }
}