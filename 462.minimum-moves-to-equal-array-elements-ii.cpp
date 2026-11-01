/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

// @lc code=start
class Solution {
public:
    int minMoves2(std::vector<int>& nums) {
        std::ranges::sort(nums);
        const int median = nums[nums.size() / 2];
        return std::ranges::fold_left(nums, 0, [median](const int lhs, const int rhs) -> int { return lhs + std::abs(rhs - median); });
    }
};
// @lc code=end
