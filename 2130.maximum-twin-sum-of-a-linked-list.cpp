/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
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
    int pairSum(const ListNode* head) {
        int res = 0;
        const ListNode* current = head;
        std::vector<int> temp;

        while (current) {
            temp.push_back(current->val);
            current = current->next;
        }
        for (int i = 0, j = temp.size() - 1; i < j; i++, j--) {
            res = std::max(res, temp[i] + temp[j]);
        }
        return res;
    }
};
// @lc code=end
