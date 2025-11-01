/*
 * @lc app=leetcode id=1624 lang=cpp
 *
 * [1624] Largest Substring Between Two Equal Characters
 */

// @lc code=start
class Solution {
public:
    int maxLengthBetweenEqualCharacters(const std::string& s) {
        const int size = s.length();
        int res = -1;

        for (int i = 0; i < size; i++) {
            const int idx = s.rfind(s[i]);
            res = std::max(res, idx == std::string::npos ? -1 : idx - i - 1);
        }
        return res;
    }
};
// @lc code=end
