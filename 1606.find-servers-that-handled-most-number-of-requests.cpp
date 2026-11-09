/*
 * @lc app=leetcode id=1606 lang=cpp
 *
 * [1606] Find Servers That Handled Most Number of Requests
 */

// @lc code=start
class Solution {
    struct Job {
        int at, server;
        std::strong_ordering operator<=>(const Job&) const = default;
    };

public:
    std::vector<int> busiestServers(int k, const std::vector<int>& arrival, const std::vector<int>& load) {
        const int size = arrival.size();
        std::vector<int> turns = std::views::iota(0, k) | std::ranges::to<std::vector>();
        std::priority_queue free(std::greater<>(), std::move(turns));
        std::priority_queue<Job, std::vector<Job>, std::greater<>> busy;
        std::vector<int> handled(k);

        for (int i = 0; i < size; i++) {
            while (!busy.empty() && busy.top().at <= arrival[i]) {
                free.push(i + (busy.top().server - i % k + k) % k);
                busy.pop();
            }
            if (!free.empty()) {
                const int x = free.top() % k;
                free.pop();
                busy.emplace(arrival[i] + load[i], x);
                handled[x]++;
            }
        }
        const int max = std::ranges::max(handled);
        return handled | std::views::enumerate |
            std::views::filter([max](const std::tuple<long, int>& element) -> bool { return std::get<1>(element) == max; }) |
            std::views::elements<0> | std::ranges::to<std::vector<int>>();
    }
};
// @lc code=end
