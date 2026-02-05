/*
 * @lc app=leetcode id=1779 lang=cpp
 *
 * [1779] Find Nearest Point That Has the Same X or Y Coordinate
 */

// @lc code=start
class Solution {
public:
    int nearestValidPoint(const int x, const int y, const std::vector<std::vector<int>>& points) {
        const int size = points.size();
        int res = -1, min = INT32_MAX;

        for (int i = 0; i < size; i++) {
            if (points[i][0] == x || points[i][1] == y) {
                const int manhattan_distance = std::abs(points[i][0] - x) + std::abs(points[i][1] - y);

                if (manhattan_distance < min) {
                    min = manhattan_distance;
                    res = i;
                }
            }
        }
        return res;
    }
};
// @lc code=end
