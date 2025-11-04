/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution {
    enum State { UNCHECKED, VISITING, SAFE, UNSAFE };

    bool dfs(const std::vector<std::vector<int>>& graph, std::vector<State>& state, const int node) {
        if (state[node] == UNSAFE || state[node] == VISITING) {
            return false;
        }
        if (state[node] == SAFE) {
            return true;
        }
        state[node] = VISITING;

        for (const int adj : graph[node]) {
            if (!dfs(graph, state, adj)) {
                state[node] = UNSAFE;
                return false;
            }
        }
        state[node] = SAFE;
        return true;
    }

public:
    std::vector<int> eventualSafeNodes(const std::vector<std::vector<int>>& graph) {
        const int size = graph.size();
        std::vector state(size, UNCHECKED);
        std::vector<int> res;

        for (int i = 0; i < size; i++) {
            if (dfs(graph, state, i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end
