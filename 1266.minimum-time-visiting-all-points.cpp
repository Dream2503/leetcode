/*
 * @lc app=leetcode id=1266 lang=cpp
 *
 * [1266] Minimum Time Visiting All Points
 */

// @lc code=start
class Solution {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        std::vector<int>& current = points[0];
        int res = 0;

        for (const std::vector<int>& element : points) {
            const int max = std::max(std::abs(element[0] - current[0]), std::abs(element[1] - current[1]));
            current = element;
            res += max;
        }
        return res;
    }
};
// @lc code=end
