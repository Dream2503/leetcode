/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    bool halvesAreAlike(const std::string& s) {
        static constexpr std::string VOWELS = "aeiouAEIOU";
        const int size = s.size();
        int res = 0;

        for (const char ch : s | std::views::take(size / 2)) {
            res += VOWELS.contains(ch);
        }
        for (const char ch : s | std::views::drop(size / 2)) {
            res -= VOWELS.contains(ch);
        }
        return res == 0;
    }
};
// @lc code=end
