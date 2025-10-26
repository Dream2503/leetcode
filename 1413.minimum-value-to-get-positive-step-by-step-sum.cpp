/*
 * @lc app=leetcode id=1413 lang=cpp
 *
 * [1413] Minimum Value to Get Positive Step by Step Sum
 */

// @lc code=start
class Solution {
public:
    int minStartValue(const std::vector<int>& nums) {
        const int size = nums.size();
        int sum = 0, res = 0;

        for (int i = 0; i < size; i++) {
            sum += nums[i];
            res = std::max(res, -sum);
        }
        return res + 1;
    }
};
// @lc code=end

