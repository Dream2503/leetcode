/*
 * @lc app=leetcode id=4006 lang=cpp
 *
 * [4006] Count Valid Prefixes
 */

// @lc code=start
class Solution {
public:
    int countValidPrefixes(const std::string& s) {
        int res = 0, diff = 0;

        for (const char ch : s) {
            res += abs(diff += ch == '1' ? 1 : -1) <= 1;
        }
        return res;
    }
};
// @lc code=end
