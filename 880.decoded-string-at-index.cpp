/*
 * @lc app=leetcode id=880 lang=cpp
 *
 * [880] Decoded String at Index
 */

// @lc code=start
class Solution {
public:
    std::string decodeAtIndex(const std::string& s, const int k) {
        uint64_t length = 0;

        for (const char ch : s) {
            length = std::isalpha(ch) ? length + 1 : length * (ch - '0');
        }
        uint64_t res = k;

        for (int i = s.size() - 1; i >= 0; --i) {
            if (std::isdigit(s[i])) {
                if ((res %= length /= s[i] - '0') == 0) {
                    res = length;
                }
            } else if (res == length--) {
                return std::string(1, s[i]);
            }
        }
        return "";
    }
};
// @lc code=end
