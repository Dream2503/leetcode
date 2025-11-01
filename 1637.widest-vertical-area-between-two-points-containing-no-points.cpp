/*
 * @lc app=leetcode id=1637 lang=cpp
 *
 * [1637] Widest Vertical Area Between Two Points Containing No Points
 */

// @lc code=start
class Solution {
public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
        const int size = points.size();
        int res = 0;
        std::ranges::sort(points, {}, [](const std::vector<int>& point) -> int { return point[0]; });

        for (int i = 1; i < size; i++) {
            res = std::max(res, std::abs(points[i][0] - points[i - 1][0]));
        }
        return res;
    }
};
// @lc code=end
