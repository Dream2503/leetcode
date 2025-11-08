/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, const int key) {
        if (root) {
            if (key < root->val) {
                root->left = deleteNode(root->left, key);
            } else if (key > root->val) {
                root->right = deleteNode(root->right, key);
            } else {
                if (!root->left && !root->right) {
                    delete root;
                    root = nullptr;
                } else if (!root->left || !root->right) {
                    const TreeNode* temp = root;

                    if (root->left) {
                        root = root->left;
                    } else {
                        root = root->right;
                    }
                    delete temp;
                } else {
                    const TreeNode* temp = root->right;

                    while (temp && temp->left) {
                        temp = temp->left;
                    }
                    root->val = temp->val;
                    root->right = deleteNode(root->right, temp->val);
                }
            }
        }
        return root;
    }
};
// @lc code=end
