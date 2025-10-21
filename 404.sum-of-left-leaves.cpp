/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    int sum(const TreeNode* node) {
        if (node) {
            if (node->left && !node->left->left && !node->left->right) {
                return node->left->val + sum(node->right);
            }
            return sum(node->left) + sum(node->right);
        }
        return 0;
    }

public:
    int sumOfLeftLeaves(TreeNode* root) { return sum(root); }
};
// @lc code=end
