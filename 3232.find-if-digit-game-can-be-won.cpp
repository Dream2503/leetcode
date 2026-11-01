/*
 * @lc app=leetcode id=3232 lang=cpp
 *
 * [3232] Find if Digit Game Can Be Won
 */

// @lc code=start
class Solution {
public:
    bool canAliceWin(const std::vector<int>& nums) {
        return std::ranges::fold_left(nums | std::views::filter([](const int num) -> bool { return num < 10; }), 0, std::plus()) !=
            std::ranges::fold_left(nums | std::views::filter([](const int num) -> bool { return num >= 10; }), 0, std::plus());
    }
};
// @lc code=end
