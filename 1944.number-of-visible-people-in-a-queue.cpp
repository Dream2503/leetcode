/*
 * @lc app=leetcode id=1944 lang=cpp
 *
 * [1944] Number of Visible People in a Queue
 */

// @lc code=start
class Solution {
public:
    std::vector<int> canSeePersonsCount(const std::vector<int>& heights) {
        const int size = heights.size();
        std::vector res(size, 0);
        std::stack<int> stack;

        for (int i = size - 1; i >= 0; i--) {
            int count = 0;

            while (!stack.empty() && heights[stack.top()] <= heights[i]) {
                count++;
                stack.pop();
            }
            res[i] = count + !stack.empty();
            stack.push(i);
        }
        return res;
    }
};
// @lc code=end
