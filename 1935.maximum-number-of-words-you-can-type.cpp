/*
 * @lc app=leetcode id=1935 lang=cpp
 *
 * [1935] Maximum Number of Words You Can Type
 */

// @lc code=start
class Solution {
public:
    int canBeTypedWords(const std::string& text, const std::string& brokenLetters) {
        const int size = text.size();
        int res = 0, i = 0;
        std::bitset<26> seen;

        for (const char ch : brokenLetters) {
            seen[ch - 'a'] = true;
        }
        while (i < size) {
            while (i < size && text[i] != ' ') {
                if (seen[text[i] - 'a']) {
                    break;
                }
                i++;
            }
            if (i >= size || text[i] == ' ') {
                res++;
            } else {
                while (i < size && text[i] != ' ') {
                    i++;
                }
            }
            i++;
        }
        return res;
    }
};
// @lc code=end
