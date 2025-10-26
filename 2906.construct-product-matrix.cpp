/*
 * @lc app=leetcode id=2906 lang=cpp
 *
 * [2906] Construct Product Matrix
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    std::vector<std::vector<int>> constructProductMatrix(const std::vector<std::vector<int>>& grid) {
        constexpr int MOD = 12345;
        const int row = grid.size(), col = grid[0].size(), size = row * col;
        std::vector prefix(row * col, 1), suffix(row * col, 1);
        std::vector res(row, std::vector(col, 0));
        int i = 1;

        for (const int element : grid | std::views::join | std::views::take(size - 1)) {
            prefix[i] = 1LL * prefix[i - 1] * element % MOD;
            i++;
        }
        i = size - 2;

        for (const int element : grid | std::views::join | std::views::reverse | std::views::take(size - 1)) {
            suffix[i] = 1LL * suffix[i + 1] * element % MOD;
            i--;
        }
        i = 0;

        for (int& element : res | std::views::join) {
            element = prefix[i] * suffix[i] % MOD;
            i++;
        }
        return res;
    }
};
// @lc code=end
