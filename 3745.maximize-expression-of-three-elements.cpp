/*
 * @lc app=leetcode id=3745 lang=cpp
 *
 * [3745] Maximize Expression of Three Elements
 */

// @lc code=start
class Solution {
public:
    int maximizeExpressionOfThree(std::vector<int>& nums) {
        std::ranges::sort(nums);
        return nums.back() + *(nums.end() - 2) - nums.front();
    }
};
// @lc code=end
