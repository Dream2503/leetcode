/*
 * @lc app=leetcode id=2373 lang=cpp
 *
 * [2373] Largest Local Values in a Matrix
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> largestLocal(const std::vector<std::vector<int>>& grid) {
        const int size = grid.size();
        std::vector<std::vector<int>> res;
        res.reserve(size - 2);

        for (int i = 1; i < size - 1; i++) {
            res.push_back({});
            res.back().reserve(size - 2);

            for (int j = 1; j < size - 1; j++) {
                res.back().push_back(std::max({
                    grid[i - 1][j - 1],
                    grid[i - 1][j],
                    grid[i - 1][j + 1],
                    grid[i][j - 1],
                    grid[i][j],
                    grid[i][j + 1],
                    grid[i + 1][j - 1],
                    grid[i + 1][j],
                    grid[i + 1][j + 1],
                }));
            }
        }
        return res;
    }
};
// @lc code=end
