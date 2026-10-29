/*
 * @lc app=leetcode id=817 lang=cpp
 *
 * [817] Linked List Components
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
    int numComponents(ListNode* head, const std::vector<int>& nums) {
        int res = 0;
        const std::unordered_set hash(nums.begin(), nums.end());

        while (head) {
            if (hash.contains(head->val)) {
                while (head && hash.contains(head->val)) {
                    head = head->next;
                }
                res++;
            } else {
                head = head->next;
            }
        }
        return res;
    }
};
// @lc code=end
