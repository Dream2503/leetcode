/*
 * @lc app=leetcode id=1360 lang=cpp
 *
 * [1360] Number of Days Between Two Dates
 */

#include <chrono>
// @lc code=start
class Solution {
    std::chrono::sys_days to_sys_days(const std::string& date) {
        return std::chrono::year_month_day(std::chrono::year(std::stoi(date.substr(0, 4))),
                                           std::chrono::month(static_cast<uint8_t>(std::stoi(date.substr(5, 2)))),
                                           std::chrono::day(static_cast<uint8_t>(std::stoi(date.substr(8, 2)))));
    }

public:
    int daysBetweenDates(const std::string& date1, const std::string& date2) { return std::abs((to_sys_days(date1) - to_sys_days(date2)).count()); }
};
// @lc code=end
