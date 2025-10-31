/*
 * @lc app=leetcode id=2608 lang=cpp
 *
 * [2608] Shortest Cycle in a Graph
 */

// @lc code=start
class Solution {
    int bfs(const std::vector<std::vector<int>>& graph, std::vector<int>& distances, std::vector<int>& parents, const int source) {
        int min = INT32_MAX;
        std::queue<int> queue;
        std::ranges::fill(distances, -1);
        std::ranges::fill(parents, -1);
        queue.push(source);
        distances[source] = 0;

        while (!queue.empty()) {
            const int node = queue.front();
            queue.pop();

            for (const int neighbour : graph[node]) {
                if (neighbour != parents[node]) {
                    if (distances[neighbour] != -1) {
                        min = std::min(min, distances[node] + distances[neighbour] + 1);
                    } else {
                        distances[neighbour] = distances[node] + 1;
                        parents[neighbour] = node;
                        queue.push(neighbour);
                    }
                }
            }
        }
        return min;
    }

public:
    int findShortestCycle(const int n, const std::vector<std::vector<int>>& edges) {
        int res = INT32_MAX;
        std::vector<std::vector<int>> graph(n);
        std::vector<int> distances(n);
        std::vector<int> parents(n);

        for (const std::vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < n; i++) {
            res = std::min(res, bfs(graph, distances, parents, i));
        }
        return res == INT32_MAX ? -1 : res;
    }
};
// @lc code=end
