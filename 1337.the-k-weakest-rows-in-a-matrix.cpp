/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    std::vector<int> kWeakestRows(const std::vector<std::vector<int>>& mat, const int k) {
        const int size = mat.size();
        std::vector<std::pair<int, int>> data;
        data.reserve(size);

        for (int i = 0; i < size; i++) {
            int count = 0;

            for (const int element : mat[i]) {
                if (element) {
                    count++;
                } else {
                    break;
                }
            }
            data.emplace_back(i, count);
        }
        std::ranges::stable_sort(data, {}, &std::pair<int, int>::second);
        std::vector<int> res;
        res.reserve(k);
        std::ranges::copy(data | std::views::take(k) | std::views::transform([](const std::pair<int, int>& pair) -> int { return pair.first; }),
                          std::back_inserter(res));
        return res;
    }
};
// @lc code=end
