/*
 * @lc app=leetcode id=1974 lang=cpp
 *
 * [1974] Minimum Time to Type Word Using Special Typewriter
 */

// @lc code=start
class Solution {
public:
    int minTimeToType(const std::string& word) {
        int res = 0, current = 0;

        for (const char ch : word) {
            const int difference = std::abs(ch - 'a' - current);
            res += std::min(difference, 26 - difference) + 1;
            current = ch - 'a';
        }
        return res;
    }
};
// @lc code=end
