/*
 * @lc app=leetcode id=1252 lang=cpp
 *
 * [1252] Cells with Odd Values in a Matrix
 */

// @lc code=start
class Solution {
public:
    int oddCells(const int m, const int n, const std::vector<std::vector<int>>& indices) {
        std::vector row(m, 0), col(n, 0);

        for (const std::vector<int>& element : indices) {
            row[element[0]] ^= 1;
            col[element[1]] ^= 1;
        }
        const int odd_rows = std::reduce(row.begin(), row.end(), 0);
        const int odd_cols = std::reduce(col.begin(), col.end(), 0);
        return odd_rows * (n - odd_cols) + (m - odd_rows) * odd_cols;
    }
};
// @lc code=end
