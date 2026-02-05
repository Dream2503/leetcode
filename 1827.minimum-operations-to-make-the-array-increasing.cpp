/*
 * @lc app=leetcode id=1827 lang=cpp
 *
 * [1827] Minimum Operations to Make the Array Increasing
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    int minOperations(const std::vector<int>& nums) {
        int res = 0, current = nums[0];

        for (const int num : nums | std::views::drop(1)) {
            if (num <= current) {
                res += current - num + 1;
                current++;
            } else {
                current = num;
            }
        }
        return res;
    }
};
// @lc code=end
