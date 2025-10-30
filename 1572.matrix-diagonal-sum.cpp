/*
 * @lc app=leetcode id=1572 lang=cpp
 *
 * [1572] Matrix Diagonal Sum
 */

// @lc code=start
class Solution {
public:
    int diagonalSum(const std::vector<std::vector<int>>& mat) {
        const int size = mat.size();
        int res = 0;

        for (int i = 0; i < size; i++) {
            res += mat[i][i] + (i != size - i - 1 ?  mat[i][size - i - 1] : 0);
        }
        return res;
    }
};
// @lc code=end
