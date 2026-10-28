/*
 * @lc app=leetcode id=2816 lang=cpp
 *
 * [2816] Double a Number Represented as a Linked List
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
    ListNode* doubleIt(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode *prev = head, *current = prev->next;
        head->val *= 2;

        if (head->val >= 10) {
            const auto new_head = new ListNode(head->val / 10);
            head->val %= 10;
            new_head->next = prev = head;
            head = new_head;
        }
        while (current) {
            prev->val += current->val * 2 / 10;
            current->val = current->val * 2 % 10;
            prev = current;
            current = current->next;
        }
        return head;
    }
};
// @lc code=end
