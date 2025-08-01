/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>>& shiftGrid(std::vector<std::vector<int>>& grid, int k) {
        const int row = grid.size(), column = grid[0].size();
        k %= row * column;
        const int row_shift = k / column, column_shit = k % column;

        if (row_shift) {
            std::rotate(grid.begin(), grid.end() - row_shift, grid.end());
        }
        if (column_shit) {
            std::vector temp(grid[row - 1].end() - column_shit, grid[row - 1].end());
            int i = row - 2;

            while (i >= 0) {
                std::move_backward(grid[i + 1].begin(), grid[i + 1].end() - column_shit, grid[i + 1].end());
                std::copy(grid[i].end() - column_shit, grid[i].end(), grid[i + 1].begin());
                i--;
            }
            std::move_backward(grid[0].begin(), grid[0].end() - column_shit, grid[0].end());
            std::move(temp.begin(), temp.end(), grid[0].begin());
        }
        return grid;
    }
};
// @lc code=end
