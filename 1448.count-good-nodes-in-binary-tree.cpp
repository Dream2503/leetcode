/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    void dfs(const TreeNode* node, int max, int& res) {
        if (!node) {
            return;
        }
        if (node->val >= max) {
            res++;
            max = node->val;
        }
        dfs(node->left, max, res);
        dfs(node->right, max, res);
    }

public:
    int goodNodes(const TreeNode* root) {
        int res = 0;
        dfs(root, root->val, res);
        return res;
    }
};
// @lc code=end
