/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution {
public:
    std::string mergeAlternately(const std::string word1, const std::string word2) {
        const int size1 = word1.size(), size2 = word2.size();
        int i = 0, j = 0;
        std::string res;
        res.reserve(size1 + size2);

        while (i < size1 && j < size2) {
            res.push_back(word1[i++]);
            res.push_back(word2[j++]);
        }
        while (i < size1) {
            res.push_back(word1[i++]);
        }
        while (j < size2) {
            res.push_back(word2[j++]);
        }
        return res;
    }
};
// @lc code=end
