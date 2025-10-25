/*
 * @lc app=leetcode id=1275 lang=cpp
 *
 * [1275] Find Winner on a Tic Tac Toe Game
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    std::string tictactoe(const std::vector<std::vector<int>>& moves) {
        enum State { X, O, N } current = X, win = N;
        std::vector board(3, std::vector(3, N));

        for (const std::vector<int>& move : moves) {
            board[move[0]][move[1]] = current;
            current = current == X ? O : X;
        }
        if (board[0][0] == board[0][1] && board[0][0] == board[0][2]) {
            win = board[0][0];
        }
        if (board[1][0] == board[1][1] && board[1][0] == board[1][2]) {
            win = board[1][0];
        }
        if (board[2][0] == board[2][1] && board[2][0] == board[2][2]) {
            win = board[2][0];
        }
        if (board[0][0] == board[1][0] && board[0][0] == board[2][0]) {
            win = board[0][0];
        }
        if (board[0][1] == board[1][1] && board[0][1] == board[2][1]) {
            win = board[0][1];
        }
        if (board[0][2] == board[1][2] && board[0][2] == board[2][2]) {
            win = board[0][2];
        }
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            win = board[0][0];
        }
        if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            win = board[0][2];
        }
        if (win != N) {
            return win == X ? "A" : "B";
        }
        if (moves.size() == 9) {
            return "Draw";
        }
        return "Pending";
    }
};
// @lc code=end
