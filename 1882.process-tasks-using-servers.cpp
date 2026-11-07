/*
 * @lc app=leetcode id=1882 lang=cpp
 *
 * [1882] Process Tasks Using Servers
 */

// @lc code=start
class Solution {
    void update(std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<std::pair<int64_t, int>>>& busy,
                std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<std::pair<int64_t, int>>>& idle,
                const std::vector<int>& servers, const int time) {
        while (!busy.empty() && busy.top().first <= time) {
            const auto& [_, idx] = busy.top();
            idle.emplace(servers[idx], idx);
            busy.pop();
        }
    }

public:
    std::vector<int> assignTasks(const std::vector<int>& servers, const std::vector<int>& tasks) {
        const int server_size = servers.size(), task_size = tasks.size();
        int64_t time = 0;
        std::vector<int> res;
        std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<std::pair<int64_t, int>>> busy, idle;

        for (int i = 0; i < server_size; i++) {
            idle.emplace(servers[i], i);
        }
        for (int i = 0; i < task_size; i++) {
            time = std::max(time, static_cast<int64_t>(i));
            update(busy, idle, servers, time);

            if (idle.empty()) {
                time = busy.top().first;
                update(busy, idle, servers, time);
            }
            const auto& [_, idx] = idle.top();
            res.push_back(idx);
            busy.emplace(time + tasks[i], idx);
            idle.pop();
        }
        return res;
    }
};
// @lc code=end
