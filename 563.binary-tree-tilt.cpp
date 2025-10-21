/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
    int resolve(const TreeNode* node, int& res) {
        if (node) {
            if (!node->left && !node->right) {
                return node->val;
            }
            int left = 0, right = 0;

            if (node->left) {
                left = resolve(node->left, res);
            }
            if (node->right) {
                right = resolve(node->right, res);
            }
            res += std::abs(left - right);
            return left + right + node->val;
        }
        return 0;
    }

public:
    int findTilt(const TreeNode* root) {
        int res = 0;
        resolve(root, res);
        return res;
    }
};
// @lc code=end
