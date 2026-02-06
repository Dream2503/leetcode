/*
 * @lc app=leetcode id=1859 lang=cpp
 *
 * [1859] Sorting the Sentence
 */

// @lc code=start
class Solution {
public:
    std::string sortSentence(const std::string& s) {
        std::string res;

        for (int i = 1; i < 10; i++) {
            const int j = s.find(i + '0');
            int k = j;

            if (j == std::string::npos) {
                break;
            }
            while (k >= 0 && s[k] != ' ') {
                k--;
            }
            res.append(s.substr(k + 1, j - k - 1));
            res.push_back(' ');
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end
