/*
 * @lc app=leetcode id=1877 lang=cpp
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */

// @lc code=start
class Solution {
public:
    int minPairSum(std::vector<int>& nums) {
        const int size = nums.size();
        std::ranges::sort(nums);
        return std::ranges::max(
            std::views::zip(nums | std::views::take(size / 2), nums | std::views::reverse | std::views::take(size / 2)) |
            std::views::transform([](const std::tuple<int, int>& element) -> int { return std::get<0>(element) + std::get<1>(element); }));
    }
};
// @lc code=end
