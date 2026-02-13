/*
 * @lc app=leetcode id=2022 lang=cpp
 *
 * [2022] Convert 1D Array Into 2D Array
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> construct2DArray(const std::vector<int>& original, const int m, const int n) {
        const int size = original.size();

        if (m * n == size) {
            int k = 0;
            std::vector res(m, std::vector(n, 0));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    res[i][j] = original[k++];
                }
            }
            return res;
        }
        return {};
    }
};
// @lc code=end
