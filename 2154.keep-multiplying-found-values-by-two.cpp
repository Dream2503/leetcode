/*
 * @lc app=leetcode id=2154 lang=cpp
 *
 * [2154] Keep Multiplying Found Values by Two
 */

// @lc code=start
class Solution {
public:
    int findFinalValue(std::vector<int>& nums, int original) {
        std::ranges::sort(nums);

        for (const int num : nums) {
            if (num == original) {
                original /= 2;
            }
        }
        return original;
    }
};
// @lc code=end
