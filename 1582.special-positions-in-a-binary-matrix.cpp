/*
 * @lc app=leetcode id=1582 lang=cpp
 *
 * [1582] Special Positions in a Binary Matrix
 */

// @lc code=start
class Solution {
public:
    int numSpecial(const std::vector<std::vector<int>>& mat) {
        const int size = mat.size();
        int res = 0;

        for (int i = 0; i < size; i++) {
            if (std::ranges::count(mat[i], 1) == 1) {
                int j = std::ranges::find(mat[i], 1) - mat[i].begin();
                res += std::ranges::count(mat, 1, [&j](const std::vector<int>& row) -> int { return row[j]; }) == 1;
            }
        }
        return res;
    }
};
// @lc code=end
