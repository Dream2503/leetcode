/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    bool search(const std::vector<int>& nums, const int target) {
        const int size = nums.size();
        int i;
        for (i = 1; i < size && nums[i - 1] <= nums[i]; i++);
        return std::binary_search(nums.begin(), nums.begin() + i, target) || std::binary_search(nums.begin() + i, nums.end(), target);
    }
};
// @lc code=end
