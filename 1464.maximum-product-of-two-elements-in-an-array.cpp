/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
 */

// @lc code=start
class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        std::ranges::partial_sort(nums, nums.begin() + 2, std::ranges::greater());
        return (nums[0] - 1) * (nums[1] - 1);
    }
};
// @lc code=end
