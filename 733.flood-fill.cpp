/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    void dfs(std::vector<std::vector<int>>& image, const int m, const int n, const int row, const int col, const int color, const int new_color) {
        if (row >= 0 && row < m && col >= 0 && col < n && image[row][col] == color && image[row][col] != new_color) {
            image[row][col] = new_color;
            dfs(image, m, n, row + 1, col, color, new_color);
            dfs(image, m, n, row - 1, col, color, new_color);
            dfs(image, m, n, row, col + 1, color, new_color);
            dfs(image, m, n, row, col - 1, color, new_color);
        }
    }

    std::vector<std::vector<int>>& floodFill(std::vector<std::vector<int>>& image, const int sr, const int sc, const int newColor) {
        dfs(image, image.size(), image.front().size(), sr, sc, image[sr][sc], newColor);
        return image;
    }
};
// @lc code=end
