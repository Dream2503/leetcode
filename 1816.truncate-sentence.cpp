/*
 * @lc app=leetcode id=1816 lang=cpp
 *
 * [1816] Truncate Sentence
 */

// @lc code=start
class Solution {
public:
    std::string truncateSentence(const std::string& s, int k) {
        const int size = s.size();
        int i = 0;

        while (i < size && k) {
            if (s[i] == ' ') {
                k--;
            }
            i++;
        }
        return s.substr(0, i - (k ? 0 : 1));
    }
};
// @lc code=end
