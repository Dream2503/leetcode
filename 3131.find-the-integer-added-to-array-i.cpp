/*
 * @lc app=leetcode id=3131 lang=cpp
 *
 * [3131] Find the Integer Added to Array I
 */

// @lc code=start
class Solution {
public:
    int addedInteger(const std::vector<int>& nums1, const std::vector<int>& nums2) { return std::ranges::min(nums2) - std::ranges::min(nums1); }
};
// @lc code=end
