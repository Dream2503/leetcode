/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
    bool dfs(std::vector<std::vector<char>>& board, const int x, const int y, const int i, const int j, const std::string& word, const int size,
             const int k) {
        if (k < size) {
            if (i >= 0 && i < x && j >= 0 && j < y && board[i][j] == word[k]) {
                board[i][j] = '#';

                for (const auto& [dx, dy] : {std::pair(-1, 0), {0, -1}, {0, 1}, {1, 0}}) {
                    const int ni = i + dx, nj = j + dy;

                    if (dfs(board, x, y, ni, nj, word, size, k + 1)) {
                        board[i][j] = word[k];
                        return true;
                    }
                }
                board[i][j] = word[k];
                return false;
            }
            return false;
        }
        return true;
    }

public:
    bool exist(std::vector<std::vector<char>>& board, const std::string& word) {
        const int row_size = board.size(), col_size = board.front().size(), size = word.length();

        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (board[i][j] == word.front() && dfs(board, row_size, col_size, i, j, word, size, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
