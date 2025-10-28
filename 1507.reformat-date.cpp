/*
 * @lc app=leetcode id=1507 lang=cpp
 *
 * [1507] Reformat Date
 */

// @lc code=start
class Solution {
public:
    std::string reformatDate(const std::string& date) {
        static const std::array<std::string, 12> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        int day, year;
        std::string month(3, 0);
        (std::stringstream(date) >> day).ignore(3) >> month >> year;
        return (std::stringstream() << year << '-' << std::setw(2) << std::setfill('0') << std::ranges::find(months, month) - months.begin() + 1
                                    << '-' << std::setw(2) << std::setfill('0') << day)
            .str();
    }
};
// @lc code=end
