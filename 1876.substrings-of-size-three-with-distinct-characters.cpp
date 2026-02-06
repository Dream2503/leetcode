/*
 * @lc app=leetcode id=1876 lang=cpp
 *
 * [1876] Substrings of Size Three with Distinct Characters
 */

// @lc code=start
class Solution {
public:
    int countGoodSubstrings(const std::string& s) {
        const int size = s.size();
        int res = 0;

        for (int i = 0; i < size - 2; i++) {
            if (s[i] != s[i + 1] and s[i + 1] != s[i + 2] and s[i + 2] != s[i]) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
