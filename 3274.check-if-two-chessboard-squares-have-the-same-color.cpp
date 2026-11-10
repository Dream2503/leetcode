/*
 * @lc app=leetcode id=3274 lang=cpp
 *
 * [3274] Check if Two Chessboard Squares Have the Same Color
 */

// @lc code=start
class Solution {
public:
    bool checkTwoChessboards(const std::string& coordinate1, const std::string& coordinate2) {
        return ((coordinate1.front() - 'a') % 2 != (coordinate1.back() - '0') % 2) ==
            ((coordinate2.front() - 'a') % 2 != (coordinate2.back() - '0') % 2);
    }
};
// @lc code=end
