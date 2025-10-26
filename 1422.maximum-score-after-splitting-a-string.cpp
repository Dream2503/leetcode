/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
class Solution {
public:
    int maxScore(const std::string& s) {
        const int size = s.length();
        int zeros = 0, ones = std::ranges::count(s, '1'), res = 0;

        for (int i = 0; i < size - 1; i++) {
            if (s[i] == '1') {
                ones--;
            } else {
                zeros++;
            }
            res = std::max(res, zeros + ones);
        }
        return res;
    }
};
// @lc code=end
