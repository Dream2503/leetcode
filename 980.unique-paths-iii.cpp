/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
class Solution {
    enum { WALL = -1, PATH = 0, VISITING = 1, END = 2 };

    void dfs(std::vector<std::vector<int>>& grid, const int x, const int y, const int i, const int j, const int path, int& explored, int& res) {
        if (i >= 0 && i < x && j >= 0 && j < y && grid[i][j] != VISITING && grid[i][j] != WALL) {
            if (grid[i][j] == PATH) {
                grid[i][j] = VISITING;
                explored++;

                for (const auto& [dx, dy] : {std::pair(-1, 0), {0, -1}, {0, 1}, {1, 0}}) {
                    dfs(grid, grid.size(), grid.front().size(), i + dx, j + dy, path, explored, res);
                }
                grid[i][j] = PATH;
                explored--;
            } else {
                res += explored == path;
            }
        }
    }

public:
    int uniquePathsIII(std::vector<std::vector<int>>& grid) {
        const int row_size = grid.size(), col_size = grid.front().size();
        int path = 0, x = -1, y = -1, explored = 0, res = 0;

        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (!grid[i][j]) {
                    path++;
                } else if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                    grid[i][j] = PATH;
                    path++;
                }
            }
        }
        dfs(grid, grid.size(), grid.front().size(), x, y, path, explored, res);
        return res;
    }
};
// @lc code=end
