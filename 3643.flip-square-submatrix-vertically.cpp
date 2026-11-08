/*
 * @lc app=leetcode id=3643 lang=cpp
 *
 * [3643] Flip Square Submatrix Vertically
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>>& reverseSubmatrix(std::vector<std::vector<int>>& grid, const int x, const int y, const int k) {
        for (int j = y; j < y + k; j++) {
            for (int i = x, l = x + k - 1; i <= l; i++, l--) {
                std::swap(grid[i][j], grid[l][j]);
            }
        }
        return grid;
    }
};
// @lc code=end
