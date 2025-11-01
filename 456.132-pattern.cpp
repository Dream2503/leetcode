/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start
class Solution {
public:
    bool find132pattern(const std::vector<int>& nums) {
        const int size = nums.size();

        if (size < 3) {
            return false;
        }
        int third = INT32_MIN;
        std::stack<int> stack;

        for (int i = size - 1; i >= 0; --i) {
            if (nums[i] < third) {
                return true;
            }
            while (!stack.empty() && nums[i] > stack.top()) {
                third = stack.top();
                stack.pop();
            }
            stack.push(nums[i]);
        }
        return false;
    }
};
// @lc code=end
