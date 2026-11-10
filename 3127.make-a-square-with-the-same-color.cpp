/*
 * @lc app=leetcode id=3127 lang=cpp
 *
 * [3127] Make a Square with the Same Color
 */

// @lc code=start
class Solution {
public:
    bool canMakeSquare(const std::vector<std::vector<char>>& grid) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                const int b = std::ranges::count(std::array{grid[i][j], grid[i][j + 1], grid[i + 1][j], grid[i + 1][j + 1]}, 'B'), w = 4 - b;

                if (b >= 3 || w >= 3) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
