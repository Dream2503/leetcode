/*
 * @lc app=leetcode id=3607 lang=cpp
 *
 * [3607] Power Grid Maintenance
 */

// @lc code=start
class Solution {
    void initialize(const int node, const int id, std::vector<int>& component, const std::vector<std::vector<int>>& graph,
                    std::vector<bool>& visited) {
        visited[node] = true;
        component[node] = id;

        for (const int connected : graph[node]) {
            if (!visited[connected]) {
                initialize(connected, id, component, graph, visited);
            }
        }
    }

public:
    std::vector<int> processQueries(const int c, const std::vector<std::vector<int>>& connections, const std::vector<std::vector<int>>& queries) {
        int id = 0;
        std::vector visited(c, false);
        std::vector<int> components(c, -1), res;
        std::vector<std::vector<int>> graph(c);

        for (const std::vector<int>& connection : connections) {
            graph[connection[0] - 1].push_back(connection[1] - 1);
            graph[connection[1] - 1].push_back(connection[0] - 1);
        }
        for (int i = 0; i < c; i++) {
            if (!visited[i]) {
                initialize(i, id++, components, graph, visited);
            }
        }
        std::vector<std::set<int>> list(id);

        for (int i = 0; i < c; i++) {
            list[components[i]].insert(i);
        }
        for (const std::vector<int>& query : queries) {
            const int component = components[query[1] - 1];

            if (query[0] == 1) {
                if (list[component].contains(query[1] - 1)) {
                    res.push_back(query[1] - 1 + 1);
                } else if (!list[component].empty()) {
                    res.push_back(*list[component].begin() + 1);
                } else {
                    res.push_back(-1);
                }
            } else if (query[0] == 2) {
                list[component].erase(query[1] - 1);
            }
        }
        return res;
    }
};
// @lc code=end
