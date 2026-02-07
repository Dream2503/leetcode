/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
class Solution {
public:
    bool validPath(const int n, const std::vector<std::vector<int>>& edges, const int source, const int destination) {
        std::unordered_set<int> seen;
        std::unordered_map<int, std::vector<int>> graph;
        std::queue<int> queue;
        queue.push(source);

        for (const std::vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        while (!queue.empty()) {
            const int node = queue.front();
            queue.pop();

            if (node == destination) {
                return true;
            }
            if (!seen.insert(node).second) {
                continue;
            }
            for (const int next : graph[node]) {
                queue.push(next);
            }
        }
        return false;
    }
};
// @lc code=end
