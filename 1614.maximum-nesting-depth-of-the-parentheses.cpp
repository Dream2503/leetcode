/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 */

// @lc code=start
class Solution {
public:
    int maxDepth(const std::string& s) {
        int current = 0, res = 0;

        for (const char ch : s) {
            if (ch == '(') {
                res = std::max(res, ++current);
            } else if (ch == ')') {
                current--;
            }
        }
        return res;
    }
};
// @lc code=end
