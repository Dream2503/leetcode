/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution {
public:
    std::string makeGood(const std::string& s) {
        const int size = s.length();
        std::string res;

        for (int i = 0; i < size; i++) {
            if (!res.empty() && (res.back() == s[i] - 32 || res.back() == s[i] + 32)) {
                res.pop_back();
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
// @lc code=end
