//
// Created by LI Tian on 13/2/22.
//

/// 104. Maximum Depth of Binary Tree
/// Given the root of a binary tree, return its maximum depth.
///
/// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

#include <catch2/catch.hpp>
#include "../../binarytree_helper.h"
#include <vector>


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return max(l, r) + 1;
    }
};

TEST_CASE( "Binary Tree TestCases") {
    SECTION("case1") {
        vector<int> nums = {3, 9, 20, null, null, 15, 7};
        BinaryTree * tree = new BinaryTree(nums);

        Solution sln = Solution();
        int ans = sln.maxDepth(tree->root());
        REQUIRE(ans==2);
    }

    SECTION("case2") {
        vector<int> nums = {2, null, 3, null, 4, null, 5, null, 6};
        BinaryTree * tree = new BinaryTree(nums);

        Solution sln = Solution();
        int ans = sln.maxDepth(tree->root());
        REQUIRE(ans==5);
    }
}
