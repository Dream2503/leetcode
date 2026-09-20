/*
 * @lc app=leetcode id=3446 lang=cpp
 *
 * [3446] Sort Matrix by Diagonals
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>>& sortMatrix(std::vector<std::vector<int>>& grid) {
        const int size = grid.size();
        std::vector<std::vector<int>> temp(2 * size - 1);

        for (int i = size - 1, k = 0; i >= 0; i--, k++) {
            for (int j = 0, l = k; j < size; j++, l++) {
                temp[l].push_back(grid[i][j]);
            }
        }
        for (std::vector<int>& diagonal : temp | std::views::take(size)) {
            std::ranges::sort(diagonal, std::ranges::greater());
        }
        for (std::vector<int>& diagonal : temp | std::views::drop(size)) {
            std::ranges::sort(diagonal);
        }
        for (int i = size - 1, k = 0; i >= 0; i--, k++) {
            for (int j = 0, l = k; j < size; j++, l++) {
                grid[i][j] = temp[l].back();
                temp[l].pop_back();
            }
        }
        return grid;
    }
};
// @lc code=end
