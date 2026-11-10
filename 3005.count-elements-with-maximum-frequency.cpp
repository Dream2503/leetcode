/*
 * @lc app=leetcode id=3005 lang=cpp
 *
 * [3005] Count Elements With Maximum Frequency
 */

// @lc code=start
class Solution {
public:
    int maxFrequencyElements(const std::vector<int>& nums) {
        const auto range = nums | std::views::transform([&nums](const int num) -> int { return std::ranges::count(nums, num); });
        return std::ranges::count(range, std::ranges::max(range));
    }
};
// @lc code=end
