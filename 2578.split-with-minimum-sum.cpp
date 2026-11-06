/*
 * @lc app=leetcode id=2578 lang=cpp
 *
 * [2578] Split With Minimum Sum
 */

// @lc code=start
class Solution {
public:
    int splitNum(const int num) {
        std::string str = std::to_string(num);
        std::ranges::sort(str);
        return std::stoi(str | std::views::stride(2) | std::ranges::to<std::string>()) +
            std::stoi(str | std::views::drop(1) | std::views::stride(2) | std::ranges::to<std::string>());
    }
};
// @lc code=end
