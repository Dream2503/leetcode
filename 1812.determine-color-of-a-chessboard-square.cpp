/*
 * @lc app=leetcode id=1812 lang=cpp
 *
 * [1812] Determine Color of a Chessboard Square
 */

// @lc code=start
class Solution {
public:
    bool squareIsWhite(const std::string& coordinates) { return (coordinates[0] - 'a') % 2 == (coordinates[1] - '0') % 2; }
};
// @lc code=end
