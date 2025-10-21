/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
    TreeNode* merge(TreeNode* node1, TreeNode* node2) {
        if (node1 && node2) {
            node1->val += node2->val;
            node1->left = merge(node1->left, node2->left);
            node1->right = merge(node1->right, node2->right);
            return node1;
        } else if (node2) {
            return node2;
        } else if (node1) {
            return node1;
        }
        return nullptr;
    }

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }
};
// @lc code=end
