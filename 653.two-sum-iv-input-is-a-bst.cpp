/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
    const TreeNode* next_smallest(std::stack<const TreeNode*>& stack) {
        const TreeNode *node = stack.top(), *current = node->right;
        stack.pop();

        while (current) {
            stack.push(current);
            current = current->left;
        }
        return node;
    }

    const TreeNode* next_largest(std::stack<const TreeNode*>& stack) {
        const TreeNode *node = stack.top(), *current = node->left;
        stack.pop();

        while (current) {
            stack.push(current);
            current = current->right;
        }
        return node;
    }

public:
    bool findTarget(const TreeNode* root, const int k) {
        std::stack<const TreeNode*> in_order, reverse;
        const TreeNode *low = root, *high = root;

        while (low) {
            in_order.push(low);
            low = low->left;
        }
        while (high) {
            reverse.push(high);
            high = high->right;
        }
        low = next_smallest(in_order);
        high = next_largest(reverse);

        while (low && high && low != high) {
            const int sum = low->val + high->val;

            if (sum < k) {
                low = next_smallest(in_order);
            } else if (sum > k) {
                high = next_largest(reverse);
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
