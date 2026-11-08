/*
 * @lc app=leetcode id=1267 lang=cpp
 *
 * [1267] Count Servers that Communicate
 */

// @lc code=start
class Solution {
public:
    int countServers(const std::vector<std::vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        int res = 0;
        std::vector row_count(rows, 0), col_count(cols, 0);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res += grid[i][j] && (row_count[i] > 1 || col_count[j] > 1);
            }
        }
        return res;
    }
};
// @lc code=end
