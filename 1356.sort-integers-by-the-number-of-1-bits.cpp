/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    std::vector<int>& sortByBits(std::vector<int>& arr) {
        std::ranges::sort(arr, {}, [](const int value) -> std::pair<int, int> { return {__builtin_popcount(value), value}; });
        return arr;
    }
};
// @lc code=end
