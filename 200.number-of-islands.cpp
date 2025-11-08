/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        const int row_size = grid.size(), col_size = grid.front().size();
        int res = 0;

        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (grid[i][j] == '1') {
                    std::queue<std::pair<int, int>> queue;
                    grid[i][j] = '0';
                    queue.emplace(i, j);

                    while (!queue.empty()) {
                        const auto [x, y] = queue.front();
                        queue.pop();

                        for (const auto& [dx, dy] : {std::pair(-1, 0), {0, -1}, {0, 1}, {1, 0}}) {
                            const int nx = x + dx, ny = y + dy;

                            if (nx >= 0 && nx < row_size && ny >= 0 && ny < col_size && grid[nx][ny] == '1') {
                                grid[nx][ny] = '0';
                                queue.emplace(nx, ny);
                            }
                        }
                    }
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
