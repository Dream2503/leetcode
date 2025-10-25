/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    std::vector<int>& arrayRankTransform(std::vector<int>& arr) {
        int size = arr.size();
        std::vector res = arr;
        std::map<int, std::vector<int>> hash;

        for (int i = 0; i < size; i++) {
            hash[arr[i]].push_back(i);
        }
        int rank = 1;
        size = hash.size();

        for (const std::vector<int>& indices : hash | std::views::values) {
            for (const int idx : indices) {
                arr[idx] = rank;
            }
            rank++;
        }
        return arr;
    }
};
// @lc code=end
