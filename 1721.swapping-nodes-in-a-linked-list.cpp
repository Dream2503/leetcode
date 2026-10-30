/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
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
    ListNode* swapNodes(ListNode* head, const int k) {
        std::vector<int> temp;
        ListNode* current = head;

        while (current) {
            temp.push_back(current->val);
            current = current->next;
        }
        std::swap(temp[k - 1], temp[temp.size() - k]);
        current = head;

        for (const int element : temp) {
            current->val = element;
            current = current->next;
        }
        return head;
    }
};
// @lc code=end
