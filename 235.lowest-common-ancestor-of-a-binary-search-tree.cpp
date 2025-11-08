/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    std::vector<TreeNode*> search(TreeNode* root, const TreeNode* node) {
        std::vector<TreeNode*> ancestors;

        while (root) {
            ancestors.push_back(root);

            if (node->val < root->val) {
                root = root->left;
            } else if (node->val > root->val) {
                root = root->right;
            } else {
                return ancestors;
            }
        }
        return {};
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, const TreeNode* p, const TreeNode* q) {
        const std::vector<TreeNode*> p_ancestors = search(root, p), q_ancestors = search(root, q);
        const int size = std::min(p_ancestors.size(), q_ancestors.size());
        int i = 0;

        while (i < size) {
            if (p_ancestors[i] != q_ancestors[i]) {
                break;
            }
            i++;
        }
        return p_ancestors[i - 1];
    }
};
// @lc code=end
