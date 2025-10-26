/*
 * @lc app=leetcode id=1379 lang=cpp
 *
 * [1379] Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original && cloned) {
            if (original == target) {
                return cloned;
            }
            if (TreeNode* res = getTargetCopy(original->left, cloned->left, target)) {
                return res;
            }
            if (TreeNode* res = getTargetCopy(original->right, cloned->right, target)) {
                return res;
            }
        }
        return nullptr;
    }
};
// @lc code=end
