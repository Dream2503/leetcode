/*
 * @lc app=leetcode id=2487 lang=cpp
 *
 * [2487] Remove Nodes From Linked List
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
    ListNode* removeNodes(ListNode* head) {
        ListNode* current = head;
        std::vector<ListNode*> stack;

        while (current) {
            while (!stack.empty() && stack.back()->val < current->val) {
                stack.pop_back();
            }
            stack.push_back(current);
            current = current->next;
        }
        head = stack.front();
        current = head;

        for (ListNode* node : stack | std::views::drop(1)) {
            current = current->next = node;
        }
        return head;
    }
};
// @lc code=end
