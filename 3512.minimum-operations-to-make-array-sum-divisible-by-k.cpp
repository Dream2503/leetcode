/*
 * @lc app=leetcode id=3512 lang=cpp
 *
 * [3512] Minimum Operations to Make Array Sum Divisible by K
 */

// @lc code=start
class Solution {
public:
    int minOperations(const std::vector<int>& nums, const int k) { return std::ranges::fold_left(nums, 0, std::plus()) % k; }
};
// @lc code=end
