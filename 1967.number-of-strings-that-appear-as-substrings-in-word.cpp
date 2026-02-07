/*
 * @lc app=leetcode id=1967 lang=cpp
 *
 * [1967] Number of Strings That Appear as Substrings in Word
 */

// @lc code=start
class Solution {
public:
    int numOfStrings(const std::vector<std::string>& patterns, const std::string& word) {
        return std::ranges::count_if(patterns, [&word](const std::string& pattern) -> bool { return word.contains(pattern); });
    }
};
// @lc code=end
