/*
 * @lc app=leetcode id=3217 lang=cpp
 *
 * [3217] Delete Nodes From Linked List Present in Array
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
    ListNode* modifiedList(const std::vector<int>& nums, ListNode* head) {
        const std::unordered_set hash(nums.begin(), nums.end());

        while (head && hash.contains(head->val)) {
            head = head->next;
        }
        ListNode *prev = head, *current = head ? head->next : head;

        while (current) {
            while (current && hash.contains(current->val)) {
                current = current->next;
            }
            prev->next = current;
            prev = current;

            if (current) {
                current = current->next;
            }
        }
        return head;
    }
};
// @lc code=end
