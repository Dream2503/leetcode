/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include <ranges>

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
        return !std::ranges::any_of(std::views::iota(0, numCourses),
                                    [&](const int i) -> bool { return state[i] == UNVISITED && !dfs(graph, state, i); });
    }
};
// @lc code=end
