/*
 * @lc app=leetcode id=3120 lang=cpp
 *
 * [3120] Count the Number of Special Characters I
 */

// @lc code=start
class Solution {
public:
    int numberOfSpecialChars(const std::string& word) {
        std::bitset<26> lower_case, upper_case;

        for (const char& ch : word) {
            (std::islower(ch) ? lower_case[ch - 'a'] : upper_case[ch - 'A']) = true;
        }
        return (lower_case & upper_case).count();
    }
};
// @lc code=end
