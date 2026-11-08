/*
 * @lc app=leetcode id=2148 lang=cpp
 *
 * [2148] Count Elements With Strictly Smaller and Greater Elements
 */

// @lc code=start
class Solution {
public:
    int countElements(const std::vector<int>& nums) {
        return std::max(
            static_cast<int>(nums.size()) - std::ranges::count(nums, std::ranges::min(nums)) - std::ranges::count(nums, std::ranges::max(nums)), 0l);
    }
};
// @lc code=end
