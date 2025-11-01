/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    std::vector<int>& dailyTemperatures(std::vector<int>& temperatures) {
        const int size = temperatures.size();
        std::stack<int> stack;

        for (int i = 0; i < size; i++) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
                temperatures[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        while (!stack.empty()) {
            temperatures[stack.top()] = 0;
            stack.pop();
        }
        return temperatures;
    }
};
// @lc code=end
