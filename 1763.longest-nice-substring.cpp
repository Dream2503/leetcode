/*
 * @lc app=leetcode id=1763 lang=cpp
 *
 * [1763] Longest Nice Substring
 */

// @lc code=start
class Solution {
    bool is_nice(const std::string& s, const int start, const int end) {
        std::array<bool, 26> lower = {}, upper = {};

        for (int i = start; i < end; i++) {
            if (std::islower(s[i])) {
                lower[s[i] - 'a'] = true;
            } else {
                upper[s[i] - 'A'] = true;
            }
        }
        return lower == upper;
    }

public:
    std::string longestNiceSubstring(const std::string& s) {
        const int size = s.size();
    std:
        std::string res;

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j <= size; j++) {
                if (is_nice(s, i, j) && j - i > res.size()) {
                    res = s.substr(i, j - i);
                }
            }
        }
        return res;
    }
};
// @lc code=end
