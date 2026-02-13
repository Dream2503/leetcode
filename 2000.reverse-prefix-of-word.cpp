/*
 * @lc app=leetcode id=2000 lang=cpp
 *
 * [2000] Reverse Prefix of Word
 */

// @lc code=start
class Solution {
public:
    std::string& reversePrefix(std::string& word, const char ch) {
        const auto itr = std::ranges::find(word, ch);

        if (itr != word.end()) {
            std::reverse(word.begin(), itr + 1);
        }
        return word;
    }
};
// @lc code=end
