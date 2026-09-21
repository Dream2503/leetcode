/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 */

// @lc code=start
class Solution {
public:
    int findMinDifference(const std::vector<std::string>& timePoints) {
        const int size = timePoints.size();
        int res = INT32_MAX;
        std::vector<int> normalized;

        for (const std::string& time_point : timePoints) {
            std::pair<int, int> time;
            std::sscanf(time_point.c_str(), "%d:%d", &time.first, &time.second);
            normalized.push_back(time.first * 60 + time.second);
        }
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                res = std::min({res, std::abs(normalized[i] - normalized[j]), std::abs(normalized[i] + 1440 - normalized[j]),
                                std::abs(normalized[i] - normalized[j] - 1440)});
            }
        }
        return res;
    }
};
// @lc code=end
