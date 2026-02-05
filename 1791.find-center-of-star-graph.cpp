/*
 * @lc app=leetcode id=1791 lang=cpp
 *
 * [1791] Find Center of Star Graph
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    int findCenter(const std::vector<std::vector<int>>& edges) {
        std::unordered_map<int, int> hash;

        for (const std::vector<int>& edge : edges) {
            hash[edge[0]]++;
            hash[edge[1]]++;
        }
        return std::ranges::max_element(hash, {}, [](const std::pair<int, int>& edge) -> int { return edge.second; })->first;
    }
};
// @lc code=end
