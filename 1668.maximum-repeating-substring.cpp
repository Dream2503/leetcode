/*
 * @lc app=leetcode id=1668 lang=cpp
 *
 * [1668] Maximum Repeating Substring
 */

// @lc code=start
class Solution {
public:
    int maxRepeating(const std::string& sequence, const std::string& word) {
        const int sequence_size = sequence.size(), word_size = word.size();
        int i = 0, res = 0;

        while (i < sequence_size) {
            int current = 0, j = 0;

            while (i < sequence_size && sequence[i] != word[j]) {
                i++;
            }
            int k = i;

            while (i < sequence_size && sequence[i] == word[j]) {
                if (j == word_size - 1) {
                    current++;
                }
                i++;
                j = (j + 1) % word_size;
            }
            i = k + 1;
            res = std::max(res, current);
        }
        return res;
    }
};
// @lc code=end
