/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        const int row_size = obstacleGrid.size(), col_size = obstacleGrid.front().size();

        if (obstacleGrid.front().front() || obstacleGrid.back().back()) {
            return 0;
        }
        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (i == 0 && j == 0) {
                    obstacleGrid[i][j] = 1;
                } else {
                    if (!obstacleGrid[i][j]) {
                        obstacleGrid[i][j] = (i > 0 ? obstacleGrid[i - 1][j] : 0) + (j > 0 ? obstacleGrid[i][j - 1] : 0);
                    } else {
                        obstacleGrid[i][j] = 0;
                    }
                }
            }
        }
        return obstacleGrid.back().back();
    }
};
// @lc code=end
