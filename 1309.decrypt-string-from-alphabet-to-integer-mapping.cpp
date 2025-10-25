/*
 * @lc app=leetcode id=1309 lang=cpp
 *
 * [1309] Decrypt String from Alphabet to Integer Mapping
 */

// @lc code=start
class Solution {
public:
    std::string freqAlphabets(const std::string& s) {
        const int size = s.length();
        std::string res;
        res.reserve(size);

        for (int i = 0; i < size; i++) {
            if (i + 2 < size && s[i + 2] == '#') {
                res += 'a' + (s[i] - '0') * 10 + s[i + 1] - '0' - 1;
                i += 2;
            } else {
                res += 'a' + s[i] - '0' - 1;
            }
        }
        return res;
    }
};
// @lc code=end
