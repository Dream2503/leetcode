/*
 * @lc app=leetcode id=1332 lang=cpp
 *
 * [1332] Remove Palindromic Subsequences
 */

// @lc code=start
class Solution {
public:
    int removePalindromeSub(const std::string& s) {
        if (s.empty()) {
            return 0;
        }
        if (s == std::string(s.rbegin(), s.rend())) {
            return 1;
        }
        return 2;
    }
};
// @lc code=end
