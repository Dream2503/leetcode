/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        const int size = intervals.size();
        int i = 1;
        std::vector<std::vector<int>> res;
        std::ranges::sort(intervals, {},
                          [](const std::vector<int>& interval) -> std::tuple<int, int> { return std::tuple(interval[0], interval[1]); });

        while (i <= size) {
            res.push_back(intervals[i - 1]);

            while (i < size && res.back()[1] >= intervals[i][0]) {
                res.back()[0] = std::min(res.back()[0], intervals[i][0]);
                res.back()[1] = std::max(res.back()[1], intervals[i][1]);
                i++;
            }
            i++;
        }
        return res;
    }
};
// @lc code=end
