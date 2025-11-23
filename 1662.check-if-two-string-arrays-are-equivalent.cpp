/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 */

// @lc code=start
class Solution {
public:
    bool arrayStringsAreEqual(const std::vector<std::string>& word1, const std::vector<std::string>& word2) {
        const int size1 = word1.size(), size2 = word2.size();
        int i = 0, j = 0, ki = 0, kj = 0;

        while (i < size1 && j < size2) {
            while (ki < word1[i].length() && kj < word2[j].length()) {
                if (word1[i][ki++] != word2[j][kj++]) {
                    return false;
                }
            }
            if (ki == word1[i].length()) {
                i++;
                ki = 0;
            }
            if (kj == word2[j].length()) {
                j++;
                kj = 0;
            }
        }
        return i == size1 && j == size2;
    }
};
// @lc code=end
