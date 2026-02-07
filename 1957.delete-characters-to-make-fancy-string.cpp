/*
 * @lc app=leetcode id=1957 lang=cpp
 *
 * [1957] Delete Characters to Make Fancy String
 */

// @lc code=start
class Solution {
public:
    std::string makeFancyString(const std::string& s) {
        const int size = s.size();
        int i = 0;
        std::string res;
        res.reserve(size);

        while (i < size) {
            while (i < size - 2 && s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
                i++;
            }
            res.push_back(s[i]);
            i++;
        }
        return res;
    }
};
// @lc code=end
