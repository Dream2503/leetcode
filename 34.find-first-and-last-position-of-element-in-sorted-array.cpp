/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    std::vector<int> searchRange(const std::vector<int>& nums, const int target) {
        const int lhs = std::ranges::lower_bound(nums, target) - nums.begin();

        if (lhs < 0 || lhs >= nums.size() || nums[lhs] != target) {
            return {-1, -1};
        }
        const int rhs = std::ranges::upper_bound(nums, target) - nums.begin() - 1;
        return {lhs, rhs};
    }
};
// @lc code=end
