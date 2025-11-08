/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    long long prev = INT64_MIN;

public:
    bool isValidBST(const TreeNode* root) {
        if (root) {
            if (!isValidBST(root->left) || prev >= root->val) {
                return false;
            }
            prev = root->val;
            return isValidBST(root->right);
        }
        return true;
    }
};
// @lc code=end
