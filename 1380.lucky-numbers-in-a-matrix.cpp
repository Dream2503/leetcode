/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
class Solution {
public:
    std::vector<int> luckyNumbers(const std::vector<std::vector<int>>& matrix) {
        const int col_size = matrix.front().size();
        std::vector<int> min_cols, res;
        min_cols.reserve(col_size);

        for (int i = 0; i < col_size; i++) {
            min_cols.push_back(std::ranges::max_element(matrix, {}, [i](const std::vector<int>& col) -> int { return col[i]; })->at(i));
        }
        for (const std::vector<int>& row : matrix) {
            const int idx = std::ranges::min_element(row) - row.begin();

            if (row[idx] == min_cols[idx]) {
                res.push_back(row[idx]);
            }
        }
        return res;
    }
};
// @lc code=end
