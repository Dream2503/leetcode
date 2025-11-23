/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        const int size = matrix.size();

        for (int k = 0; k < size / 2; k++) {
            for (int i = 0; i < size - 1 - 2 * k; i++) {
                std::swap(matrix[k][i + k], matrix[i + k][size - 1 - k]);
                std::swap(matrix[k][i + k], matrix[size - 1 - k][size - 1 - k - i]);
                std::swap(matrix[k][i + k], matrix[size - 1 - k - i][k]);
            }
        }
    }
};
// @lc code=end
