/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
    enum State { UNVISITED, VISITING, VISITED };

    bool dfs(std::vector<std::vector<int>>& graph, std::vector<State>& state, const int source) {
        state[source] = VISITING;

        for (const int adj : graph[source]) {
            if (state[adj] == VISITING || state[adj] == UNVISITED && !dfs(graph, state, adj)) {
                return false;
            }
        }
        state[source] = VISITED;
        return true;
    }

public:
    bool canFinish(const int numCourses, const std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph(numCourses);
        std::vector state(numCourses, UNVISITED);

        for (const std::vector<int>& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == UNVISITED && !dfs(graph, state, i)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
