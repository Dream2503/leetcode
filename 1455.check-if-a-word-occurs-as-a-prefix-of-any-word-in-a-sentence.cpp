/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    int isPrefixOfWord(const std::string& sentence, const std::string& searchWord) {
        int i = 1;

        for (auto&& word : sentence | std::views::split(' ')) {
            if (std::string(word.begin(), word.end()).starts_with(searchWord)) {
                return i;
            }
            i++;
        }
        return -1;
    }
};
// @lc code=end
