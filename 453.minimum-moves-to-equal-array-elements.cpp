/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 */

// @lc code=start
class Solution {
public:
    int minMoves(const std::vector<int>& nums) { return std::ranges::fold_left(nums, 0l, std::plus()) - nums.size() * std::ranges::min(nums); }
};
// @lc code=end
