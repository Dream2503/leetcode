/*
 * @lc app=leetcode id=3536 lang=cpp
 *
 * [3536] Maximum Product of Two Digits
 */

// @lc code=start
class Solution {
public:
    int maxProduct(int n) {
        int max1 = 0, max2 = 0;

        while (n) {
            if (const int digit = n % 10; digit >= max1) {
                max2 = max1;
                max1 = digit;
            } else if (digit > max2) {
                max2 = digit;
            }
            n /= 10;
        }
        return max1 * max2;
    }
};
// @lc code=end
