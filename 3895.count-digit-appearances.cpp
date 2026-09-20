/*
 * @lc app=leetcode id=3895 lang=cpp
 *
 * [3895] Count Digit Appearances
 */

// @lc code=start
class Solution {
public:
    int countDigitOccurrences(const std::vector<int>& nums, const int digit) {
        return std::ranges::fold_left(
            nums, 0, [digit](const int lhs, const int rhs) -> int { return lhs + std::ranges::count(std::to_string(rhs), digit + '0'); });
    }
};
// @lc code=end
