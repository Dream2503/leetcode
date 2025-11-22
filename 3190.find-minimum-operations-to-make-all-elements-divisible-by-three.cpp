/*
 * @lc app=leetcode id=3190 lang=cpp
 *
 * [3190] Find Minimum Operations to Make All Elements Divisible by Three
 */

// @lc code=start
class Solution {
public:
    int minimumOperations(const std::vector<int>& nums) {
        return std::ranges::count_if(nums, [](const int num) -> bool { return num % 3 != 0; });
    }
};
// @lc code=end
