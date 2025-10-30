/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start'
class Solution {
    void dfs(const int i, const int j, const int row_size, const int col_size, std::vector<std::vector<char>>& grid) {
        if (i >= 0 && i < row_size && j >= 0 && j < col_size && grid[i][j] == 'O') {
            grid[i][j] = '#';
            dfs(i - 1, j, row_size, col_size, grid);
            dfs(i, j - 1, row_size, col_size, grid);
            dfs(i, j + 1, row_size, col_size, grid);
            dfs(i + 1, j, row_size, col_size, grid);
        }
    }

public:
    void solve(std::vector<std::vector<char>>& grid) {
        const int row_size = grid.size(), col_size = grid[0].size();

        for (int i = 0; i < row_size; i++) {
            if (grid[i][0] == 'O') {
                dfs(i, 0, row_size, col_size, grid);
            }
            if (grid[i][col_size - 1] == 'O') {
                dfs(i, col_size - 1, row_size, col_size, grid);
            }
        }
        for (int j = 0; j < col_size; j++) {
            if (grid[0][j] == 'O') {
                dfs(0, j, row_size, col_size, grid);
            }
            if (grid[row_size - 1][j] == 'O') {
                dfs(row_size - 1, j, row_size, col_size, grid);
            }
        }
        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (grid[i][j] == 'O')
                    grid[i][j] = 'X';
                else if (grid[i][j] == '#')
                    grid[i][j] = 'O';
            }
        }
    }
};
// @lc code=end
