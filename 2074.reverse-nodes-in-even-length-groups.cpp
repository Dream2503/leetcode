/*
 * @lc app=leetcode id=2074 lang=cpp
 *
 * [2074] Reverse Nodes in Even Length Groups
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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int i = 0, group = 2;
        ListNode *current = head->next, *prev = head;

        while (current) {
            ListNode *temp = current, *group_tail = nullptr;

            for (i = 0; i < group && current; i++) {
                group_tail = current;
                current = current->next;
            }
            if (i % 2 == 0) {
                ListNode *tail = temp, *before = nullptr;

                for (int j = 0; j < i; j++) {
                    ListNode* next = temp->next;
                    temp->next = before;
                    before = temp;
                    temp = next;
                }
                prev->next = before;
                tail->next = current;
                prev = tail;
            } else {
                prev = group_tail;
            }
            group++;
        }
        return head;
    }
};
// @lc code=end
