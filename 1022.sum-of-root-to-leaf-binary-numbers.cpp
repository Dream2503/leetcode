/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
    void resolve(const TreeNode* node, int& res, const int num) {
        if (node) {
            if (!node->left && !node->right) {
                res += num * 2 + node->val;
            } else {
                resolve(node->left, res, num * 2 + node->val);
                resolve(node->right, res, num * 2 + node->val);
            }
        }
    }

public:
    int sumRootToLeaf(const TreeNode* root) {
        int res = 0;
        resolve(root, res, 0);
        return res;
    }
};
// @lc code=end
