/*
 * @lc app=leetcode id=1185 lang=cpp
 *
 * [1185] Day of the Week
 */

// @lc code=start
class Solution {
public:
    std::string dayOfTheWeek(const int d, int m, int y) {
        // I have no idea how do this work
        static constexpr std::string days[] = {"Saturday",  "Sunday",   "Monday", "Tuesday",
                                               "Wednesday", "Thursday", "Friday"};
        if (m < 3) {
            m += 12;
            y--;
        }
        const int k = y % 100, j = y / 100;
        return days[(d + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7];
    }
};
// @lc code=end
