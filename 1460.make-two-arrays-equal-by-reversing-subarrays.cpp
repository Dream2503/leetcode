/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Subarrays
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    bool canBeEqual(const std::vector<int>& target, const std::vector<int>& arr) {
        std::unordered_map<int, int> hash;

        for (const int value : arr) {
            hash[value]++;
        }
        for (const int value : target) {
            hash[value]--;
        }
        return !std::ranges::any_of(hash | std::views::values, [](const int value) -> bool { return value; });
    }
};
// @lc code=end
