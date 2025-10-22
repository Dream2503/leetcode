/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
    bool resolve(const TreeNode* node, std::vector<int>& leafs, int& index) {
        if (node) {
            if (!node->left && !node->right) {
                std::cout << node->val << std::endl;
                if (index >= 0) {
                    return leafs[index++] == node->val;
                }
                leafs.push_back(node->val);
                return true;
            }
            return resolve(node->left, leafs, index) && resolve(node->right, leafs, index);
        }
        return true;
    }

public:
    bool leafSimilar(const TreeNode* root1, const TreeNode* root2) {
        int index = -1;
        std::vector<int> leafs;
        resolve(root1, leafs, index);
        index = 0;
        return resolve(root2, leafs, index) && index == leafs.size();
    }
};
// @lc code=end
