/*
 * @lc app=leetcode id=3542 lang=cpp
 *
 * [3542] Minimum Operations to Convert All Elements to Zero
 */

// @lc code=start
class Solution {
public:
    int minOperations(const std::vector<int>& nums) {
        int res = 0;
        std::stack<int> stack;

        for (const int num : nums) {
            while (!stack.empty() && stack.top() > num) {
                stack.pop();
            }
            if (num && (stack.empty() || stack.top() < num)) {
                res++;
                stack.push(num);
            }
        }
        return res;
    }
};
// @lc code=end
