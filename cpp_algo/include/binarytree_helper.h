//
// Created by LI Tian on 13/2/22.
//

#ifndef CPP_ALGO_BINARYTREE_HELPER_H
#define CPP_ALGO_BINARYTREE_HELPER_H

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define null INT_MIN

class BinaryTree {
public:
    BinaryTree(vector<int> & nums) : m_shouldPass(false) {
        for (int i = 0; i < nums.size(); ++i) {
            if (i != null) {
                TreeNode * node = new TreeNode(nums[i]);
                if(i==0) m_root = node;
                bfs_insert(node);
            } else {
                // 当 i 为null时候，需要更新 m_visited
                m_shouldPass = true;
            }
        }
    }

    ~BinaryTree() { }

    TreeNode* root() { return m_root; }

private:
    TreeNode * m_root;
    bool m_shouldPass;


    TreeNode* bfs_insert(TreeNode* root) {
        if(root==nullptr) return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left != nullptr) {
                q.push(node->left);
            } else {
                node->left = new TreeNode(root->val);
                return root;
            };

            if (node->right != nullptr) {
                q.push(node->right);
            } else {
                node->right = new TreeNode(root->val);
                return root;
            }
        }
    }
};


#endif //CPP_ALGO_BINARYTREE_HELPER_H
