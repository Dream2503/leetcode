/*
 * @lc app=leetcode id=3693 lang=cpp
 *
 * [3693] Climbing Stairs II
 */

// @lc code=start
class Solution {
public:
    int climbStairs(const int n, const std::vector<int>& costs) {
        int a = 0, b = 0, c = 0;

        for (int i = 0; i < n; i++) {
            std::tie(a, b, c) = std::tuple(b, c, std::min({a + 9, b + 4, c + 1}) + costs[i]);
        }
        return c;
    }
};
// @lc code=end
