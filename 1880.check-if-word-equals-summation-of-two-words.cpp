/*
 * @lc app=leetcode id=1880 lang=cpp
 *
 * [1880] Check if Word Equals Summation of Two Words
 */

// @lc code=start
class Solution {
    int to_int(const std::string& str) {
        int res = 0;

        for (const char ch : str) {
            res = res * 10 + (ch - 'a');
        }
        return res;
    }

public:
    bool isSumEqual(const std::string& firstWord, const string& secondWord, const std::string& targetWord) {
        return to_int(firstWord) + to_int(secondWord) == to_int(targetWord);
    }
};
// @lc code=end
