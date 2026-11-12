/*
 * @lc app=leetcode id=4052 lang=cpp
 *
 * [4052] Cyclically Shift Rows and Columns
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>>& cyclicShift(const int n, std::vector<std::vector<int>>& grid, const std::vector<int>& rowShift,
                                               const std::vector<int>& colShift) {
        for (auto [row, value] : std::views::zip(grid, rowShift)) {
            std::ranges::rotate(row, row.begin() + value);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                std::swap(grid[i][j], grid[j][i]);
            }
        }
        for (auto [col, value] : std::views::zip(grid, colShift)) {
            std::ranges::rotate(col, col.begin() + value);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                std::swap(grid[i][j], grid[j][i]);
            }
        }
        return grid;
    }
};
// @lc code=end
