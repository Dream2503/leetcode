/*
 * @lc app=leetcode id=1232 lang=cpp
 *
 * [1232] Check If It Is a Straight Line
 */

// @lc code=start
class Solution {
public:
    bool checkStraightLine(const std::vector<std::vector<int>>& pos) {
        const int size = pos.size();
        bool on_y;
        double slope = 0;

        if (!(pos[1][0] - pos[0][0])) {
            on_y = true;
        } else {
            on_y = false;
            slope = (pos[1][1] - pos[0][1]) / static_cast<double>(pos[1][0] - pos[0][0]);
        }
        for (int i = 2; i < size; i++) {
            if (on_y && pos[i][0] - pos[i - 1][0] ||
                !on_y && slope != (pos[i][1] - pos[i - 1][1]) / static_cast<double>(pos[i][0] - pos[i - 1][0])) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
