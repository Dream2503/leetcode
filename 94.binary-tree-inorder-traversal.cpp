/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    void in_order(const TreeNode* node, std::vector<int>& res) {
        if (node) {
            in_order(node->left, res);
            res.push_back(node->val);
            in_order(node->right, res);
        }
    }

public:
    std::vector<int> inorderTraversal(const TreeNode* root) {
        std::vector<int> res;
        in_order(root, res);
        return res;
    }
};
// @lc code=end
