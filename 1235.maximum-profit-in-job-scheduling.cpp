/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
class Solution {
public:
    int jobScheduling(const std::vector<int>& startTime, const std::vector<int>& endTime, const std::vector<int>& profit) {
        const int size = startTime.size();
        std::vector<std::tuple<int, int, int>> jobs;
        jobs.reserve(size);

        for (int i = 0; i < size; i++) {
            jobs.emplace_back(endTime[i], startTime[i], profit[i]);
        }
        std::vector<int> dp(size);
        std::ranges::sort(jobs);
        dp[0] = std::get<2>(jobs[0]);

        for (int i = 1; i < size; i++) {
            int current = std::get<2>(jobs[i]);
            const int j = std::ranges::upper_bound(jobs, std::get<1>(jobs[i]), {},
                                                   [](const std::tuple<int, int, int>& job) -> int { return std::get<0>(job); }) -
                jobs.begin() - 1;

            if (j >= 0) {
                current += dp[j];
            }
            dp[i] = std::max(dp[i - 1], current);
        }
        return dp.back();
    }
};
// @lc code=end
