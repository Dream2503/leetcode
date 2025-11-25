/*
 * @lc app=leetcode id=1015 lang=cpp
 *
 * [1015] Smallest Integer Divisible by K
 */

// @lc code=start
class Solution {
public:
    int smallestRepunitDivByK(const int k) {
        if (k % 2 != 0 && k % 5 != 0) {
            int res = 0;

            for (int i = 1; i <= k; i++) {
                res = (res * 10 + 1) % k;

                if (res == 0) {
                    return i;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
