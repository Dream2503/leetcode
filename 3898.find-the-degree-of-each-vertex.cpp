/*
 * @lc app=leetcode id=3898 lang=cpp
 *
 * [3898] Find the Degree of Each Vertex
 */

// @lc code=start
class Solution {
public:
    std::vector<int> findDegrees(const std::vector<std::vector<int>>& matrix) {
        return matrix | std::views::transform([](const std::vector<int>& vec) -> int { return std::ranges::count(vec, 1); }) |
            std::ranges::to<std::vector>();
    }
};
// @lc code=end
