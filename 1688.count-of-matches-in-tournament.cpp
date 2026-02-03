/*
 * @lc app=leetcode id=1688 lang=cpp
 *
 * [1688] Count of Matches in Tournament
 */

// @lc code=start
class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;

        while (n > 1) {
            res += n / 2;
            n = (n + 1) / 2;
        }
        return res;
    }
};
// @lc code=end

