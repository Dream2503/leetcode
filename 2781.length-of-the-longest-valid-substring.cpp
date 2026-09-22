/*
 * @lc app=leetcode id=2781 lang=cpp
 *
 * [2781] Length of the Longest Valid Substring
 */

// @lc code=start
class Solution {
public:
    int longestValidSubstring(const std::string& word, const std::vector<std::string>& forbidden) {
        int res = 0, left = 0;
        const int size = word.size();
        const std::unordered_set exclude(forbidden.begin(), forbidden.end());

        for (int right = 0; right < size; right++) {
            std::string substr;

            for (int i = right; i >= left && right - i < 10; i--) {
                substr.insert(substr.begin(), word[i]);

                if (exclude.contains(substr)) {
                    left = i + 1;
                    break;
                }
            }
            res = std::max(res, right - left + 1);
        }
        return res;
    }
};
// @lc code=end
