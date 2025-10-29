/*
 * @lc app=leetcode id=1716 lang=cpp
 *
 * [1716] Calculate Money in Leetcode Bank
 */

// @lc code=start
class Solution {
    int sum_natural(const int start, const int end) { return (end - start + 1) * (start + end) / 2; }

public:
    int totalMoney(int n) {
        const int weeks = n / 7, days = n % 7;
        int res = 0;

        for (int i = 0; i < weeks; i++) {
            res += sum_natural(i + 1, i + 7);
        }
        return res + sum_natural(weeks + 1, weeks + days);
    }
};
// @lc code=end
