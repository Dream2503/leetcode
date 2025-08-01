/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 */

// @lc code=start
class Solution {
public:
    int balancedStringSplit(const std::string& s) {
        const int len = s.length();
        int res = 0, i = 0, left = 0, right = 0;

        while (i < len) {
            if (s[i] == 'L') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                res++;
                left = right = 0;
            }
            i++;
        }
        return res;
    }
};
// @lc code=end

