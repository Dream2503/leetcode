/*
 * @lc app=leetcode id=1266 lang=cpp
 *
 * [1266] Minimum Time Visiting All Points
 */

// @lc code=start
class Solution {
public:
    int minTimeToVisitAllPoints(const std::vector<std::vector<int>>& points) {
        int res = 0;
        std::vector current{points[0][0], points[0][1]};

        for (const std::vector<int>& element : points) {
            int min = std::min(element[0], element[1]), max = std::max(current[0], current[1]);
            int diff = std::abs(min - max);
            res += diff;

        }
    }
};
// @lc code=end

