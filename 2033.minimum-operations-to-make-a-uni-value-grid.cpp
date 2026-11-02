/*
 * @lc app=leetcode id=2033 lang=cpp
 *
 * [2033] Minimum Operations to Make a Uni-Value Grid
 */

// @lc code=start
class Solution {
public:
    int minOperations(const std::vector<std::vector<int>>& grid, const int x) {
        int res = 0;
        std::vector<int> flat = grid | std::views::join | std::ranges::to<std::vector<int>>();
        std::ranges::sort(flat);
        const int median = flat[flat.size() / 2];

        for (const int num : flat) {
            if (std::abs(num - median) % x != 0) {
                return -1;
            }
            res += std::abs(num - median) / x;
        }
        return res;
    }
};
// @lc code=end
