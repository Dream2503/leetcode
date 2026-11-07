/*
 * @lc app=leetcode id=3386 lang=cpp
 *
 * [3386] Button with Longest Push Time
 */

// @lc code=start
class Solution {
public:
    int buttonWithLongestTime(const std::vector<std::vector<int>>& events) {
        int res = events.front().front(), time = events.front().back(), current = 0;

        for (const std::vector<int>& event : events) {
            if (const int duration = event.back() - current; duration > time || (duration == time && event.front() < res)) {
                time = duration;
                res = event.front();
            }
            current = event.back();
        }
        return res;
    }
};
// @lc code=end
