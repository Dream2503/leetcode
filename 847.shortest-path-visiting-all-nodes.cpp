/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
class Solution {
    struct State {
        int mask, node, steps;
    };

    size_t hash(const State& state) {
        size_t hash = 31;
        hash = hash * 31 + std::hash<int>()(state.mask);
        hash = hash * 31 + std::hash<int>()(state.node);
        return hash;
    }

public:
    int shortestPathLength(const std::vector<std::vector<int>>& graph) {
        const int size = graph.size(), terminate = (1 << size) - 1;
        std::queue<State> queue;
        std::unordered_set<size_t> seen;

        for (int i = 0; i < size; i++) {
            queue.emplace(1 << i, i, 0);
            seen.insert(hash(queue.back()));
        }
        while (!queue.empty()) {
            const auto [mask, node, steps] = queue.front();
            queue.pop();

            if (mask == terminate) {
                return steps;
            }
            for (const int next : graph[node]) {
                State state = {mask | 1 << next, next, steps + 1};

                if (seen.insert(hash(state)).second) {
                    queue.push(state);
                }
            }
        }
        return -1;
    }
};
// @lc code=end
