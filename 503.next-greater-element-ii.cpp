/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
public:
    std::vector<int> nextGreaterElements(const std::vector<int>& nums) {
        const int size = nums.size();
        std::vector res(size, -1);
        std::stack<int> stack;

        for (int i = 0; i < size * 2; i++) {
            while (!stack.empty() && nums[i % size] > nums[stack.top()]) {
                res[stack.top()] = nums[i % size];
                stack.pop();
            }
            if (i < size) {
                stack.push(i);
            }
        }
        return res;
    }
};
// @lc code=end
