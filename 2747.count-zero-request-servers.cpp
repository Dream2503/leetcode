/*
 * @lc app=leetcode id=2747 lang=cpp
 *
 * [2747] Count Zero Request Servers
 */

// @lc code=start
class Solution {
public:
    std::vector<int> countServers(const int n, const std::vector<std::vector<int>>& logs, const int x, const std::vector<int>& queries) {
        const int logs_size = logs.size(), queries_size = queries.size();
        int left = 0, right = 0;
        int active = 0;
        std::vector<std::pair<int, int>> sorted_logs = logs |
            std::views::transform([](const std::vector<int>& log) -> std::pair<int, int> { return {log[1], log[0] - 1}; }) |
            std::ranges::to<std::vector>();
        std::vector<std::pair<int, int>> sorted_queries = std::views::iota(0, queries_size) |
            std::views::transform([queries](const int i) -> std::pair<int, int> { return {queries[i], i}; }) | std::ranges::to<std::vector>();
        std::vector hash(n, 0), res(queries_size, 0);
        std::ranges::sort(sorted_logs);
        std::ranges::sort(sorted_queries);

        for (const auto& [query, index] : sorted_queries) {
            while (right < logs_size && sorted_logs[right].first <= query) {
                if (hash[sorted_logs[right++].second]++ == 0) {
                    active++;
                }
            }
            while (left < right && sorted_logs[left].first < query - x) {
                if (--hash[sorted_logs[left++].second] == 0)
                    active--;
            }
            res[index] = n - active;
        }
        return res;
    }
};
// @lc code=end
