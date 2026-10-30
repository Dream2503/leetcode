/*
 * @lc app=leetcode id=2181 lang=cpp
 *
 * [2181] Merge Nodes in Between Zeros
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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* current = head;

        while (true) {
            while (current->next->val != 0) {
                current->val += current->next->val;
                current->next = current->next->next;
            }
            if (!current->next->next) {
                break;
            }
            current = current->next;
        }
        current->next = nullptr;
        return head;
    }
};
// @lc code=end
