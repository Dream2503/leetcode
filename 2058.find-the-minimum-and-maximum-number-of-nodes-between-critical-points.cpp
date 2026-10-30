/*
 * @lc app=leetcode id=2058 lang=cpp
 *
 * [2058] Find the Minimum and Maximum Number of Nodes Between Critical Points
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
    std::vector<int> nodesBetweenCriticalPoints(const ListNode* head) {
        const ListNode *prev = head, *current = head->next, *next = current->next;
        int i = 1;
        std::vector<int> critical_points;

        while (next != nullptr) {
            if (prev->val < current->val && next->val < current->val || prev->val > current->val && next->val > current->val) {
                critical_points.push_back(i);
            }
            i++;
            prev = current;
            current = next;
            next = next->next;
        }
        const int size = critical_points.size();
        int res = INT32_MAX;

        if (size >= 2) {
            for (i = 1; i < size; i++) {
                res = std::min(res, critical_points[i] - critical_points[i - 1]);
            }
            return {res, critical_points.back() - critical_points.front()};
        }
        return {-1, -1};
    }
};
// @lc code=end
