/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    std::vector<int> largestValues(TreeNode* root) {
        if (!root) {
            return {};
        }
        std::vector<int> res;
        std::vector current{root};

        while (!current.empty()) {
            int max = INT32_MIN;
            std::vector<TreeNode*> next;

            for (const TreeNode* node : current) {
                if (node->left) {
                    next.push_back(node->left);
                }
                if (node->right) {
                    next.push_back(node->right);
                }
                max = std::max(max, node->val);
            }
            res.push_back(max);
            current.swap(next);
            next.clear();
        }
        return res;
    }
};
// @lc code=end
