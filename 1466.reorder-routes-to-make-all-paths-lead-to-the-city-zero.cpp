/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
class Solution {
    void dfs(const std::vector<std::unordered_set<int>>& directed_graph, const std::vector<std::vector<int>>& undirected_graph, const int node,
             std::vector<uint8_t>& seen, int& res) {
        seen[node] = true;

        for (const int next : undirected_graph[node]) {
            if (!seen[next]) {
                if (directed_graph[node].contains(next)) {
                    res++;
                }
                dfs(directed_graph, undirected_graph, next, seen, res);
            }
        }
    }

public:
    int minReorder(int n, const std::vector<std::vector<int>>& connections) {
        const int size = connections.size();
        int res = 0;
        std::vector<uint8_t> seen(n, false);
        std::vector<std::vector<int>> undirected_graph(n);
        std::vector<std::unordered_set<int>> directed_graph(n);

        for (const std::vector<int>& connection : connections) {
            directed_graph[connection[0]].insert(connection[1]);
            undirected_graph[connection[0]].push_back(connection[1]);
            undirected_graph[connection[1]].push_back(connection[0]);
        }
        dfs(directed_graph, undirected_graph, 0, seen, res);
        return res;
    }
};
// @lc code=end
