/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void pre_order(TreeNode* node, TreeNode*& prev) {
        if (!node) {
            return;
        }
        TreeNode *left = node->left, *right = node->right;

        if (prev) {
            prev->right = node;
        }
        node->left = nullptr;
        prev = node;
        pre_order(left, prev);
        pre_order(right, prev);
    }

public:
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        pre_order(root, prev);
    }
};
// @lc code=end
