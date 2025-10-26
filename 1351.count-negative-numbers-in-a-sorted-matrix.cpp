/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int countNegatives(const std::vector<std::vector<int>>& grid) {
        const int row_size = grid.size(), col_size = grid.front().size();
        int res = 0, j = col_size - 1;

        for (int i = 0; i < row_size; i++) {
            while (j >= 0 && grid[i][j] < 0) {
                j--;
            }
            res += col_size - j - 1;

            if (j < 0) {
                return res + (row_size - i - 1) * col_size;
            }
        }
        return res;
    }
};
// @lc code=end
