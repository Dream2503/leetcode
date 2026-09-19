/*
 * @lc app=leetcode id=1958 lang=cpp
 *
 * [1958] Check if Move is Legal
 */

// @lc code=start
class Solution {
public:
    bool checkMove(const std::vector<std::vector<char>>& board, const int rMove, const int cMove, const char color) {
        std::initializer_list<std::pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        if (board[rMove][cMove] != '.') {
            return false;
        }
        for (const auto& [dx, dy] : directions) {
            int distance = 0;
            int next_x = rMove + dx, next_y = cMove + dy;

            if (next_x >= 0 && next_x < 8 && next_y >= 0 && next_y < 8 && board[next_x][next_y] != '.' && board[next_x][next_y] != color) {
                while (next_x >= 0 && next_x < 8 && next_y >= 0 && next_y < 8) {
                    if (board[next_x][next_y] == '.') {
                        distance = 0;
                        break;
                    }
                    if (board[next_x][next_y] == color) {
                        if (distance >= 1) {
                            return true;
                        }
                        break;
                    }
                    next_x += dx;
                    next_y += dy;
                    distance++;
                }
            }
        }
        return false;
    }
};
// @lc code=end
