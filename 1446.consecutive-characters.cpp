/*
 * @lc app=leetcode id=1446 lang=cpp
 *
 * [1446] Consecutive Characters
 */

// @lc code=start
class Solution {
public:
    int maxPower(const std::string& s) {
        const int size = s.length();
        int res = 0, i = 0;

        while (i < size) {
            int current = 1, j = i + 1;

            while (j < size && s[i] == s[j]) {
                current++;
                j++;
            }
            res = std::max(res, current);
            i = j;
        }
        return res;
    }
};
// @lc code=end
