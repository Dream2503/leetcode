/*
 * @lc app=leetcode id=1557 lang=cpp
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */

// @lc code=start
class Solution {
public:
    std::vector<int> findSmallestSetOfVertices(const int n, const std::vector<std::vector<int>>& edges) {
        std::vector<uint8_t> incoming(n, false);

        for (const std::vector<int>& edge : edges) {
            incoming[edge[1]] = true;
        }
        return std::views::iota(0, n) | std::views::filter([&incoming](const int i) -> bool { return !incoming[i]; }) |
            std::ranges::to<std::vector<int>>();
    }
};
// @lc code=end
