/*
 * @lc app=leetcode id=2810 lang=cpp
 *
 * [2810] Faulty Keyboard
 */

// @lc code=start
class Solution {
public:
    std::string finalString(const std::string& s) {
        std::string res;

        for (const char ch : s) {
            if (ch == 'i') {
                std::ranges::reverse(res);
            } else {
                res.push_back(ch);
            }
        }
        return res;
    }
};
// @lc code=end
