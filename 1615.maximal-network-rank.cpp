/*
 * @lc app=leetcode id=1615 lang=cpp
 *
 * [1615] Maximal Network Rank
 */

// @lc code=start
class Solution {
public:
    int maximalNetworkRank(const int n, const std::vector<std::vector<int>>& roads) {
        std::unordered_map<int, std::unordered_set<int>> graph;

        for (const std::vector<int>& road : roads) {
            graph[road[0]].insert(road[1]);
            graph[road[1]].insert(road[0]);
        }
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res = std::max(res, static_cast<int>(graph[i].size() + graph[j].size() - (graph[i].contains(j) && graph[j].contains(i))));
            }
        }
        return res;
    }
};
// @lc code=end
