/*
 * @lc app=leetcode id=1805 lang=cpp
 *
 * [1805] Number of Different Integers in a String
 */

// @lc code=start
class Solution {
public:
    int numDifferentIntegers(const std::string& word) {
        const int size = word.size();
        int i = 0;
        std::unordered_set<std::string> seen;

        while (i < size) {
            while (i < size && !std::isdigit(word[i])) {
                i++;
            }
            int j = 0, k = 0;

            while (i + j < size && std::isdigit(word[i + j])) {
                j++;
            }
            while (k < j - 1 && word[i + k] == '0') {
                k++;
            }
            if (j) {
                seen.insert(word.substr(i + k, j - k));
            }
            i += j;
        }
        return seen.size();
    }
};
// @lc code=end
