/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
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
    void search(const TreeNode* node, const int min, long& res) {
        if (!node) {
            return;
        }
        if (node->val > min && node->val < res) {
            res = node->val;
        }
        search(node->left, min, res);
        search(node->right, min, res);
    }

public:
    int findSecondMinimumValue(const TreeNode* root) {
        if (!root) {
            return -1;
        }
        long res = LONG_MAX;
        search(root, root->val, res);
        return res == LONG_MAX ? -1 : res;
    }
};

// @lc code=end
