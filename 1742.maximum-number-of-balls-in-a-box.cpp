/*
 * @lc app=leetcode id=1742 lang=cpp
 *
 * [1742] Maximum Number of Balls in a Box
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    int countBalls(const int lowLimit, const int highLimit) {
        std::unordered_map<int, int> hash;

        for (int i = lowLimit; i <= highLimit; i++) {
            int temp = i, sum = 0;

            while (temp) {
                sum += temp % 10;
                temp /= 10;
            }
            hash[sum]++;
        }
        return *std::ranges::max_element(hash | std::views::values);
    }
};
// @lc code=end

