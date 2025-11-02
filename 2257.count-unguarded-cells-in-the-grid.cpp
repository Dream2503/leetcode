/*
 * @lc app=leetcode id=2257 lang=cpp
 *
 * [2257] Count Unguarded Cells in the Grid
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    int countUnguarded(const int m, const int n, const std::vector<std::vector<int>>& guards, const std::vector<std::vector<int>>& walls) {
        enum State { UNVISITED, VISITED, GUARD, WALL };
        std::vector grid(m, std::vector(n, UNVISITED));

        for (const std::vector<int>& wall : walls) {
            grid[wall[0]][wall[1]] = WALL;
        }
        for (const std::vector<int>& guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == GUARD) {
                    int k = i - 1;

                    while (k >= 0 && grid[k][j] != GUARD && grid[k][j] != WALL) {
                        grid[k][j] = VISITED;
                        k--;
                    }
                    k = j - 1;

                    while (k >= 0 && grid[i][k] != GUARD && grid[i][k] != WALL) {
                        grid[i][k] = VISITED;
                        k--;
                    }
                    k = j + 1;

                    while (k < n && grid[i][k] != GUARD && grid[i][k] != WALL) {
                        grid[i][k] = VISITED;
                        k++;
                    }
                    k = i + 1;

                    while (k < m && grid[k][j] != GUARD && grid[k][j] != WALL) {
                        grid[k][j] = VISITED;
                        k++;
                    }
                }
            }
        }
        return std::ranges::count_if(grid | std::views::join, [](State state) -> bool { return state == UNVISITED; });
    }
};
// @lc code=end
