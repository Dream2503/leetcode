/*
 * @lc app=leetcode id=2506 lang=cpp
 *
 * [2506] Count Pairs Of Similar Strings
 */

// @lc code=start
class Solution {
public:
    int similarPairs(std::vector<std::string>& words) {
        const int size = words.size();
        int res = 0;

        for (int i = 0; i < size; i++) {
            std::ranges::sort(words[i]);
            words[i].resize(std::ranges::unique(words[i]).begin() - words[i].begin());
        }
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                res += words[i] == words[j];
            }
        }
        return res;
    }
};
// @lc code=end
