/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    void path(const TreeNode* node, const std::string& current, std::vector<std::string>& paths) {
        if (node) {
            if (!node->left && !node->right) {
                paths.emplace_back(current + std::to_string(node->val));
            } else {
                path(node->left, current + std::to_string(node->val) + "->", paths);
                path(node->right, current + std::to_string(node->val) + "->", paths);
            }
        }
    }

public:
    std::vector<std::string> binaryTreePaths(const TreeNode* root) {
        std::vector<std::string> res;
        path(root, "", res);
        return res;
    }
};
// @lc code=end
