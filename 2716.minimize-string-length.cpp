/*
 * @lc app=leetcode id=2716 lang=cpp
 *
 * [2716] Minimize String Length
 */

// @lc code=start
class Solution {
public:
    int minimizedStringLength(const std::string& s) { return std::unordered_set(s.begin(), s.end()).size(); }
};
// @lc code=end
