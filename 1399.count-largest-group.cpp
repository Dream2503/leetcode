/*
 * @lc app=leetcode id=1399 lang=cpp
 *
 * [1399] Count Largest Group
 */

// @lc code=start
#include <ranges>

class Solution {
    int sum(int num) {
        int res = 0;

        while (num) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
public:
    int countLargestGroup(const int n) {
        std::unordered_map<int, int> hash;

        for (int i = 1; i <= n; i++) {
            hash[sum(i)]++;
        }
        int max = *std::ranges::max_element(hash | std::views::values);
        return std::ranges::count(hash | std::views::values, max);
    }
};
// @lc code=end
