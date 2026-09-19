/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
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
public:
    int maxLevelSum(const TreeNode* root) {
        int i = 0, res = 0, max_value = INT32_MIN;
        std::vector current = {root};

        while (!current.empty()) {
            int value = 0;
            std::vector<const TreeNode*> next;

            for (const TreeNode* node : current) {
                if (node->left) {
                    next.push_back(node->left);
                }
                if (node->right) {
                    next.push_back(node->right);
                }
                value += node->val;
            }
            i++;
            current = std::move(next);

            if (value > max_value) {
                max_value = value;
                res = i;
            }
        }
        return res;
    }
};
// @lc code=end
