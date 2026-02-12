/*
 * @lc app=leetcode id=1979 lang=cpp
 *
 * [1979] Find Greatest Common Divisor of Array
 */

// @lc code=start
class Solution {
public:
    int findGCD(const std::vector<int>& nums) {
        const auto [min, max] = std::ranges::minmax(nums);
        return std::gcd(min, max);
    }
};
// @lc code=end
