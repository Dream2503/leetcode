/*
 * @lc app=leetcode id=1893 lang=cpp
 *
 * [1893] Check if All the Integers in a Range Are Covered
 */

// @lc code=start
class Solution {
public:
    bool isCovered(const std::vector<std::vector<int>>& ranges, const int left, const int right) {
        std::vector distribution(51, false);

        for (const std::vector<int>& range : ranges) {
            for (int i = range[0]; i <= range[1]; i++) {
                distribution[i] = true;
            }
        }
        return std::ranges::all_of(distribution.begin() + left, distribution.begin() + right + 1, [](const bool element) -> bool { return element; });
    }
};
// @lc code=end
