/*
 * @lc app=leetcode id=3417 lang=cpp
 *
 * [3417] Zigzag Grid Traversal With Skip
 */

// @lc code=start
class Solution {
public:
    std::vector<int> zigzagTraversal(std::vector<std::vector<int>>& grid) {
        const int size = grid.size();

        for (int i = 1; i < size; i += 2) {
            std::ranges::reverse(grid[i]);
        }
        return grid | std::views::join | std::views::stride(2) | std::ranges::to<std::vector>();
    }
};
// @lc code=end
