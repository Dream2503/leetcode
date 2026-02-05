/*
 * @lc app=leetcode id=1758 lang=cpp
 *
 * [1758] Minimum Changes To Make Alternating Binary String
 */

// @lc code=start
class Solution {
    int alternate(const std::string& s, int start) {
        int res = 0;

        for (const char ch : s) {
            res += ch != '0' + start;
            start = (start + 1) % 2;
        }
        return res;
    }

public:
    int minOperations(const std::string& s) { return std::min(alternate(s, 0), alternate(s, 1)); }
};
// @lc code=end
