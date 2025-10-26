/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 */

// @lc code=start
class Solution {
public:
    std::vector<std::string> stringMatching(const std::vector<std::string>& words) {
        const int size = words.size();
        std::vector<std::string> res;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i != j) {
                    if (words[j].contains(words[i])) {
                        res.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
