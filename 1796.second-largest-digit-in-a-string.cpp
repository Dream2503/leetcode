/*
 * @lc app=leetcode id=1796 lang=cpp
 *
 * [1796] Second Largest Digit in a String
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    int secondHighest(const std::string& s) {
        int max = -1, res = -1;

        for (const char ch : s | std::views::filter([](const char c) -> bool { return std::isdigit(c); })) {
            const int digit = ch - '0';

            if (digit > max) {
                res = max;
                max = digit;
            } else if (digit < max && digit > res) {
                res = digit;
            }
        }
        return res;
    }
};
// @lc code=end
