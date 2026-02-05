/*
 * @lc app=leetcode id=1844 lang=cpp
 *
 * [1844] Replace All Digits with Characters
 */

// @lc code=start
class Solution {
public:
    std::string& replaceDigits(std::string& s) {
        const int size = s.size();

        for (int i = 0; i < size; i += 2) {
            s[i + 1] = s[i] + s[i + 1] - '0';
        }
        return s;
    }
};
// @lc code=end
