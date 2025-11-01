/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
    enum State { UNVISITED, VISITING, VISITED };

    bool topological_sort(const std::vector<std::vector<int>>& graph, std::vector<State>& state, const int source, std::vector<int>& res,
                          int& index) {
        state[source] = VISITING;

        for (const int adj : graph[source]) {
            if (state[adj] == VISITING || state[adj] == UNVISITED && !topological_sort(graph, state, adj, res, index)) {
                return false;
            }
        }
        state[source] = VISITED;
        res[--index] = source;
        return true;
    }

public:
    std::vector<int> findOrder(const int numCourses, const std::vector<std::vector<int>>& prerequisites) {
        int index = numCourses;
        std::vector<std::vector<int>> graph(numCourses);
        std::vector state(numCourses, UNVISITED);
        std::vector res(numCourses, -1);

        for (const std::vector<int>& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == UNVISITED && !topological_sort(graph, state, i, res, index)) {
                return {};
            }
        }
        return res;
    }
};
// @lc code=end
