/*
 * @lc app=leetcode id=2980 lang=cpp
 *
 * [2980] Check if Bitwise OR Has Trailing Zeros
 */

// @lc code=start
class Solution {
public:
    bool hasTrailingZeros(const std::vector<int>& nums) {
        return std::ranges::count_if(nums, [](const int x) -> bool { return x % 2 == 0; }) >= 2;
    }
};
// @lc code=end
