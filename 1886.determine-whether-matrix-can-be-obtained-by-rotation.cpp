/*
 * @lc app=leetcode id=1886 lang=cpp
 *
 * [1886] Determine Whether Matrix Can Be Obtained By Rotation
 */

// @lc code=start
class Solution {
public:
    bool findRotation(std::vector<std::vector<int>>& mat, const std::vector<std::vector<int>>& target) {
        const int size = mat.size();

        for (int i = 0; i < 4; i++) {
            std::ranges::reverse(mat);

            for (int j = 0; j < size; j++) {
                for (int k = 0; k < j; k++) {
                    std::swap(mat[j][k], mat[k][j]);
                }
            }
            if (mat == target) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
