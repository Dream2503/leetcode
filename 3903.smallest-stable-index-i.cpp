/*
 * @lc app=leetcode id=3903 lang=cpp
 *
 * [3903] Smallest Stable Index I
 */

// @lc code=start
class Solution {
public:
    int firstStableIndex(const std::vector<int>& nums, const int k) {
        auto range = std::views::iota(0, static_cast<int>(nums.size())) | std::views::transform([&nums](const int index) -> int {
                         return std::ranges::max(nums | std::views::take(index + 1)) - std::ranges::min(nums | std::views::drop(index));
                     });
        if (const auto itr = std::ranges::find_if(range, [k](const int value) -> bool { return value <= k; }); itr != range.end()) {
            return itr - range.begin();
        }
        return -1;
    }
};
// @lc code=end
