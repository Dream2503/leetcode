/*
 * @lc app=leetcode id=3461 lang=cpp
 *
 * [3461] Check If Digits Are Equal in String After Operations I
 */

// @lc code=start
class Solution {
public:
    bool hasSameDigits(std::string& s) {
        int size = s.size();

        while (size > 2) {
            s = s | std::views::slide(2) |
                std::views::transform([](const auto window) -> char { return (window.front() - '0' + window.back() - '0') % 10 + '0'; }) |
                std::ranges::to<std::string>();
            size--;
        }
        return s.front() == s.back();
    }
};
// @lc code=end
