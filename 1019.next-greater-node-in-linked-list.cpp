/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
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
    std::vector<int> nextLargerNodes(ListNode* head) {
        int i = 0;
        std::stack<std::pair<int, ListNode*>> stack;
        std::vector<int> res;

        while (head) {
            while (!stack.empty() && head->val > stack.top().second->val) {
                res[stack.top().first] = head->val;
                stack.pop();
            }
            stack.emplace(i++, head);
            res.push_back(0);
            head = head->next;
        }
        return res;
    }
};
// @lc code=end
