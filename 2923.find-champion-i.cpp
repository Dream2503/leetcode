/*
 * @lc app=leetcode id=2923 lang=cpp
 *
 * [2923] Find Champion I
 */

// @lc code=start
class Solution {
public:
    int findChampion(const std::vector<std::vector<int>>& grid) {
        return std::ranges::find(grid, grid.size() - 1, [](const std::vector<int>& vec) -> int { return std::ranges::count(vec, 1); }) - grid.begin();
    }
};
// @lc code=end
