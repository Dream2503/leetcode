/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
class Solution {
public:
    std::vector<int>& runningSum(std::vector<int>& nums) {
        std::inclusive_scan(nums.begin(), nums.end(), nums.begin());
        return nums;
    }
};
// @lc code=end
