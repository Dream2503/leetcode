/*
 * @lc app=leetcode id=1171 lang=cpp
 *
 * [1171] Remove Zero Sum Consecutive Nodes from Linked List
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* current = head;
        std::vector<int> vec;

        while (current) {
            vec.push_back(current->val);
            current = current->next;
        }
        for (int i = 0; i < vec.size(); i++) {
            int sum = 0;

            for (int j = i; j < vec.size(); j++) {
                sum += vec[j];

                if (sum == 0) {
                    vec.erase(vec.begin() + i, vec.begin() + j + 1);
                    i--;
                    break;
                }
            }
        }
        ListNode res(0);
        current = &res;

        for (const int value : vec) {
            current->next = new ListNode(value);
            current = current->next;
        }
        return res.next;
    }
};
// @lc code=end
