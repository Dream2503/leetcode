/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>>& updateMatrix(std::vector<std::vector<int>>& mat) {
        const int row_size = mat.size(), col_size = mat.front().size();
        std::queue<std::tuple<int, int, int>> queue;

        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (!mat[i][j]) {
                    queue.emplace(i, j, 0);
                } else {
                    mat[i][j] = -1;
                }
            }
        }
        while (!queue.empty()) {
            const auto [x, y, distance] = queue.front();
            queue.pop();

            for (const auto [dx, dy] : {std::pair(-1, 0), {0, -1}, {0, 1}, {1, 0}}) {
                const int x2 = x + dx, y2 = y + dy;

                if (x2 >= 0 && x2 < row_size && y2 >= 0 && y2 < col_size && mat[x2][y2] == -1) {
                    mat[x2][y2] = distance + 1;
                    queue.emplace(x2, y2, distance + 1);
                }
            }
        }
        return mat;
    }
};
// @lc code=end
