/*
 * @lc app=leetcode id=1367 lang=cpp
 *
 * [1367] Linked List in Binary Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool match(const ListNode* head, const TreeNode* root) {
        if (!head) {
            return true;
        }
        if (!root || root->val != head->val) {
            return false;
        }
        return match(head->next, root->left) || match(head->next, root->right);
    }

    bool pre_order(const ListNode* head, const TreeNode* root) {
        if (!root) {
            return false;
        }
        return match(head, root) || pre_order(head, root->left) || pre_order(head, root->right);
    }

public:
    bool isSubPath(const ListNode* head, const TreeNode* root) { return pre_order(head, root); }
};

// @lc code=end
