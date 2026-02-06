/*
 * @lc app=leetcode id=1854 lang=cpp
 *
 * [1854] Maximum Population Year
 */

// @lc code=start
class Solution {
public:
    int maximumPopulation(const std::vector<std::vector<int>>& logs) {
        std::array<2050 - 1950 + 1, int> distribution;

        for (const std::vector<int>& log : logs) {
            for (int i = log[0]; i < log[1]; i++) {
                distribution[i - 1950]++;
            }
        }
        return std::ranges::max_element(distribution) - distribution.begin() + 1950;
    }
};
// @lc code=end
