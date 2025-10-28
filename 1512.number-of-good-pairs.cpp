/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    int numIdenticalPairs(const std::vector<int>& nums) {
        int res = 0;
        std::unordered_map<int, int> hash;

        for (const int num : nums) {
            hash[num]++;
        }
        for (const int n : hash | std::views::values) {
            res += n * (n - 1) / 2;
        }
        return res;
    }
};
// @lc code=end
