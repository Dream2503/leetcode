/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(const std::string& text1, const std::string& text2) {
        const auto& [small, large] =
            std::minmax(text1, text2, [](const std::string& lhs, const std::string& rhs) -> bool {
                return lhs.length() < rhs.length();
            });
        const int min = small.length(), max = large.length();
        std::vector lcs(min + 1, 0);

        for (int i = 1; i <= max; i++) {
            int prev = lcs[0], current = lcs[1];

            for (int j = 1; j <= min; j++) {
                if (large[i - 1] == small[j - 1]) {
                    lcs[j] = prev + 1;
                } else if (lcs[j] < lcs[j - 1]) {
                    lcs[j] = lcs[j - 1];
                }
                prev = current;

                if (j < min) {
                    current = lcs[j + 1];
                }
            }
        }
        return lcs[min];
    }
};
// @lc code=end
