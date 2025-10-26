/*
 * @lc app=leetcode id=1374 lang=cpp
 *
 * [1374] Generate a String With Characters That Have Odd Counts
 */

// @lc code=start
class Solution {
public:
    std::string generateTheString(const int n) {
        std::string res(n, 'a');

        if (n % 2 == 0) {
            res.back() = 'b';
        }
        return res;
    }
};
// @lc code=end
