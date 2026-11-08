/*
 * @lc app=leetcode id=2717 lang=cpp
 *
 * [2717] Semi-Ordered Permutation
 */

// @lc code=start
class Solution {
public:
    int semiOrderedPermutation(const std::vector<int>& nums) {
        const int size = nums.size(), i = std::ranges::find(nums, 1) - nums.begin(), j = std::ranges::find(nums, size) - nums.begin();
        return i + size - j - 1 - (i > j);
    }
};
// @lc code=end
