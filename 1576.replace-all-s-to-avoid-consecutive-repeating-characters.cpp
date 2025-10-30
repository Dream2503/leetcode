/*
 * @lc app=leetcode id=1576 lang=cpp
 *
 * [1576] Replace All ?'s to Avoid Consecutive Repeating Characters
 */

// @lc code=start
class Solution {
public:
    std::string& modifyString(std::string& s) {
        const int size = s.length();

        for (int i = 0; i < size; i++) {
            if (s[i] == '?') {
                for (const char ch : {'a', 'b', 'c'}) {
                    if ((i == 0 || s[i - 1] != ch) && (i == size || s[i + 1] != ch)) {
                        s[i] = ch;
                        break;
                    }
                }
            }
        }
        return s;
    }
};
// @lc code=end
