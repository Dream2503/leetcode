/*
 * @lc app=leetcode id=4030 lang=cpp
 *
 * [4030] Check ASCII Palindromic
 */

// @lc code=start
class Solution {
public:
    bool isPalindromic(const std::string& s) {
        const std::string transformed = s | std::views::transform([](const char ch) -> std::string { return std::bitset<8>(ch).to_string(); }) |
            std::views::join | std::ranges::to<std::string>();
        return std::ranges::equal(transformed, transformed | std::views::reverse);
    }
};
// @lc code=end
