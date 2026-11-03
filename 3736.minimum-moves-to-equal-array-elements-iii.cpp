/*
 * @lc app=leetcode id=3736 lang=cpp
 *
 * [3736] Minimum Moves to Equal Array Elements III
 */

// @lc code=start
class Solution {
public:
    int minMoves(const std::vector<int>& nums) {
        int max = std::ranges::max(nums);
        return std::ranges::fold_left(nums, 0, [max](const int lhs, const int rhs) -> int { return lhs + max - rhs; });
    }
};
// @lc code=end
