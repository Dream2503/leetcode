/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
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
    void resolve(const TreeNode* node, TreeNode*& res) {
        if (node) {
            resolve(node->left, res);
            res->right = new TreeNode(node->val);
            res = res->right;
            resolve(node->right, res);
        }
    }

public:
    TreeNode* increasingBST(const TreeNode* root) {
        TreeNode* res = new TreeNode(), *temp = res;
        resolve(root, temp);
        return res->right;
    }
};
// @lc code=end
