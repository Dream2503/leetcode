/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    void resolve(const TreeNode* node, int& prev, int& min) {
        if (node) {
            resolve(node->left, prev, min);
            min = std::min(min, std::abs(node->val - prev));
            prev = node->val;
            resolve(node->right, prev, min);
        }
    }

public:
    int getMinimumDifference(const TreeNode* root) {
        int min = INT32_MAX, prev = min;
        resolve(root, prev, min);
        return min;
    }
};
// @lc code=end
