/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    std::vector<double> averageOfLevels(TreeNode* root) {
        int64_t sum = 0, count = 0;
        std::vector<double> res;
        std::queue<TreeNode*> queue;
        queue.push(root);
        queue.push(nullptr);

        while (count || queue.front()) {
            TreeNode* node = queue.front();
            queue.pop();

            if (node) {
                sum += node->val;
                count++;

                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            } else {
                res.push_back(static_cast<double>(sum) / count);
                queue.push(nullptr);
                sum = count = 0;
            }
        }
        return res;
    }
};

// @lc code=end
