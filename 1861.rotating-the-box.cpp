/*
 * @lc app=leetcode id=1861 lang=cpp
 *
 * [1861] Rotating the Box
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<char>> rotateTheBox(const std::vector<std::vector<char>>& boxGrid) {
        const int row = boxGrid.front().size(), col = boxGrid.size();
        std::vector res(row, std::vector(col, ' '));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                res[i][j] = boxGrid[col - 1 - j][i];
            }
        }
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (res[i][j] == '#') {
                    int k = i + 1;
                    res[i][j] = '.';

                    while (k < row) {
                        if (res[k][j] == '*' || res[k][j] == '#') {
                            break;
                        }
                        k++;
                    }
                    if (k - 1 != i)
                        res[k - 1][j] = '#';
                    else
                        res[i][j] = '#';
                }
            }
        }
        return res;
    }
};
// @lc code=end
