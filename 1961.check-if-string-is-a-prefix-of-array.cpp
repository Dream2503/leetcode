/*
 * @lc app=leetcode id=1961 lang=cpp
 *
 * [1961] Check If String Is a Prefix of Array
 */

// @lc code=start
class Solution {
public:
    bool isPrefixString(const std::string& s, const std::vector<std::string>& words) {
        const int s_size = s.size(), words_size = words.size();
        int i = 0, j = 0;

        while (i < s_size && j < words_size) {
            const int word_size = words[j].size();
            int k = 0;

            while (i < s_size && k < word_size) {
                if (s[i] != words[j][k]) {
                    return false;
                }
                i++;
                k++;
            }
            if (k < word_size) {
                return false;
            }
            j++;
        }
        return i >= s_size;
    }
};
// @lc code=end
