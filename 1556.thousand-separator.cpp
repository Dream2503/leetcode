/*
 * @lc app=leetcode id=1556 lang=cpp
 *
 * [1556] Thousand Separator
 */

// @lc code=start
class Solution {
public:
    std::string thousandSeparator(const int n) {
        std::string res = std::to_string(n);

        for (int i = res.length() - 3; i > 0; i -= 3) {
            res.insert(res.begin() + i, '.');
        }
        return res;
    }
};
// @lc code=end
