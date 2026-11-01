/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, const int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        const auto itr = std::ranges::lower_bound(matrix, target, {}, [](const std::vector<int>& row) -> int { return row.front(); });

        if (itr != matrix.end() && itr->front() == target) {
            return true;
        }
        if (itr == matrix.begin()) {
            return false;
        }
        return std::ranges::binary_search(*(itr - 1), target);
    }
};
// @lc code=end
