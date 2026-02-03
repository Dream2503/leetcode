/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
class Solution {
public:
    int countConsistentStrings(const std::string& allowed, const std::vector<std::string>& words) {
        std::bitset<26> frequency = {};

        for (const char ch : allowed) {
            frequency[ch - 'a'] = true;
        }
        return std::ranges::count_if(words, [&frequency](const std::string& word) -> bool {
            return std::ranges::all_of(word, [&frequency](const char ch) -> bool { return frequency[ch - 'a']; });
        });
    }
};
// @lc code=end
