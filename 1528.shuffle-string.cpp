/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1528] Shuffle String
 */

// @lc code=start
class Solution {
public:
    std::string restoreString(const std::string& s, const vector<int>& indices) {
        const int size = s.length();
        std::string res(s.length(), 0);

        for (int i = 0; i < size; i++) {
            res[indices[i]] = s[i];
        }
        return res;
    }
};
// @lc code=end
