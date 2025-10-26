/*
 * @lc app=leetcode id=1403 lang=cpp
 *
 * [1403] Minimum Subsequence in Non-Increasing Order
 */

// @lc code=start
class Solution {
public:
    std::vector<int> minSubsequence(std::vector<int>& nums) {
        const int size = nums.size();
        std::ranges::sort(nums, std::ranges::greater());
        int sum = std::reduce(nums.begin(), nums.end(), 0), i = 0;

        while (sum >= 0) {
            sum -= nums[i] * 2;
            i++;
        }
        return std::vector(nums.begin(), nums.begin() + i);
    }
};
// @lc code=end
