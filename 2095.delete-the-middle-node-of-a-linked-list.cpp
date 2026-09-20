/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) {
            return nullptr;
        }
        ListNode* prev = nullptr, *current = head, *next = head;

        while (next->next) {
            prev = current;
            current = current->next;
            next = next->next;

            if (next->next) {
                next = next->next;
            }
        }
        prev->next = current->next;
        delete current;
        return head;
    }
};
// @lc code=end

