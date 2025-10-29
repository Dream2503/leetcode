/*
 * @lc app=leetcode id=3370 lang=cpp
 *
 * [3370] Smallest Number With All Set Bits
 */

// @lc code=start
class Solution {
public:
    int smallestNumber(const int n) {
        for (int i = 0; i < 32; i++) {
            if (1 << i > n) {
                return (1 << i) - 1;
            }
        }
        return -1;
    }
};
// @lc code=end
