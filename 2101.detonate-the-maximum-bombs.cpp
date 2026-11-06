/*
 * @lc app=leetcode id=2101 lang=cpp
 *
 * [2101] Detonate the Maximum Bombs
 */

// @lc code=start
class Solution {
    int dfs(const std::vector<std::vector<int>>& graph, const int u, std::vector<uint8_t>& visited) {
        visited[u] = true;

        return std::ranges::fold_left(graph[u] | std::views::filter([&visited](const int v) -> bool { return !visited[v]; }) |
                                          std::views::transform([&](const int v) -> int { return dfs(graph, v, visited); }),
                                      1, std::plus());
    }

public:
    int maximumDetonation(const std::vector<std::vector<int>>& bombs) {
        const int size = bombs.size();
        std::vector<std::vector<int>> graph(size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i != j && std::pow(bombs[i][0] - bombs[j][0], 2) + std::pow(bombs[i][1] - bombs[j][1], 2) <= std::pow(bombs[i][2], 2)) {
                    graph[i].push_back(j);
                }
            }
        }
        return std::ranges::max(std::views::iota(0, size) | std::views::transform([&](const int i) -> int {
                                    std::vector<uint8_t> visited(size, false);
                                    return dfs(graph, i, visited);
                                }));
    }
};
// @lc code=end
