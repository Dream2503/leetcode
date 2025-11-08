/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(const int m, const int n) {
        std::vector dp(n, 1);

        for (int i = 1; i < m; i++) {
            std::inclusive_scan(dp.begin(), dp.end(), dp.begin(), std::plus(), 0);
        }
        return dp.back();
    }
};
// @lc code=end
