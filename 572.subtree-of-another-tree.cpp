/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool resolve(const TreeNode* node, const TreeNode* sub_node) {
        if (!node && !sub_node) {
            return true;
        }
        if (node && sub_node && node->val == sub_node->val) {
            return resolve(node->left, sub_node->left) && resolve(node->right, sub_node->right);
        }
        return false;
    }

public:
    bool isSubtree(const TreeNode* root, const TreeNode* subRoot) {
        if (root) {
            bool found = false;

            if (root->val == subRoot->val) {
                found = resolve(root, subRoot);
            }
            return found || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
        return false;
    }
};
// @lc code=end
