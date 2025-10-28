/*
 * @lc app=leetcode id=1450 lang=cpp
 *
 * [1450] Number of Students Doing Homework at a Given Time
 */

// @lc code=start
class Solution {
public:
    int busyStudent(const std::vector<int>& startTime, const std::vector<int>& endTime, const int queryTime) {
        const int size = startTime.size();
        int res = 0;

        for (int i = 0; i < size; i++) {
            res += queryTime >= startTime[i] && queryTime <= endTime[i];
        }
        return res;
    }
};
// @lc code=end
