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
    bool check(const TreeNode* node, const TreeNode* sub_node) {
        if (!node && !sub_node) {
            return true;
        }
        if (node && sub_node && node->val == sub_node->val) {
            return check(node->left, sub_node->left) && check(node->right, sub_node->right);
        }
        return false;
    }

    bool resolve(const TreeNode* node, const TreeNode* sub_root) {
        if (node) {
            bool found = false;

            if (node->val == sub_root->val) {
                found = check(node, sub_root);
            }
            return found || resolve(node->left, sub_root) || resolve(node->right, sub_root);
        }
        return false;
    }

public:
    bool isSubtree(const TreeNode* root, const TreeNode* subRoot) { return resolve(root, subRoot); }
};
// @lc code=end
