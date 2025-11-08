/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* create_node(const std::vector<int>& nums, const int low, const int high) -> TreeNode* {
        if (low > high) {
            return nullptr;
        }
        const int mid = (low + high) / 2;
        return new TreeNode(nums[mid], create_node(nums, low, mid - 1), create_node(nums, mid + 1, high));
    }

public:
    TreeNode* sortedArrayToBST(const std::vector<int>& nums) { return create_node(nums, 0, nums.size() - 1); }
};
// @lc code=end
