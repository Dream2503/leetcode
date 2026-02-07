/*
 * @lc app=leetcode id=1941 lang=cpp
 *
 * [1941] Check if All Characters Have Equal Number of Occurrences
 */

// @lc code=start
class Solution {
public:
    bool areOccurrencesEqual(const std::string& s) {
        std::array<int, 26> seen = {};

        for (const char ch : s) {
            seen[ch - 'a']++;
        }
        int res = *std::ranges::max_element(seen);
        return std::ranges::all_of(seen, [res](const int element) -> bool { return element == 0 || element == res; });
    }
};
// @lc code=end
