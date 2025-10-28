/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */

// @lc code=start
class Solution {
public:
    double average(const std::vector<int>& salary) {
        auto [min, max] = std::ranges::minmax_element(salary);
        return (std::reduce(salary.begin(), salary.end(), 0, std::plus()) - *min - *max) / (salary.size() - 2.0);
    }
};
// @lc code=end
