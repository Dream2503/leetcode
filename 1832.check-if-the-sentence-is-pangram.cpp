/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 */

// @lc code=start
class Solution {
public:
    bool checkIfPangram(const std::string& sentence) {
        std::bitset<26> seen;

        for (const char ch : sentence) {
            seen[ch - 'a'] = true;
        }
        return seen.count() == 26;
    }
};
// @lc code=end
