/*
 * @lc app=leetcode id=3612 lang=cpp
 *
 * [3612] Process String with Special Operations I
 */

// @lc code=start
class Solution {
public:
    std::string processStr(const std::string& s) {
        std::string res;

        for (const char ch : s) {
            switch (ch) {
            case '*':
                if (!res.empty()) {
                    res.pop_back();
                }
                break;

            case '#':
                res.append(res);
                break;

            case '%':
                std::ranges::reverse(res);
                break;

            default:
                res.push_back(ch);
                break;
            }
        }
        return res;
    }
};
// @lc code=end
