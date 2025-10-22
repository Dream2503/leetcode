/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
    void resolve(const TreeNode* node, const int x, const int y, const TreeNode* parent, const int depth, const TreeNode*& parent_x,
                 const TreeNode*& parent_y, int& depth_x, int& depth_y) {
        if (!node) {
            return;
        }
        if (node->val == x) {
            parent_x = parent;
            depth_x = depth;
        } else if (node->val == y) {
            parent_y = parent;
            depth_y = depth;
        }
        resolve(node->left, x, y, node, depth + 1, parent_x, parent_y, depth_x, depth_y);
        resolve(node->right, x, y, node, depth + 1, parent_x, parent_y, depth_x, depth_y);
    }

public:
    bool isCousins(const TreeNode* root, const int x, const int y) {
        const TreeNode *parent_x = nullptr, *parent_y = nullptr;
        int depth_x = -1, depth_y = -1;
        resolve(root, x, y, nullptr, 0, parent_x, parent_y, depth_x, depth_y);
        return depth_x == depth_y && parent_x != parent_y;
    }
};
// @lc code=end
