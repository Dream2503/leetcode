/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            const uint32_t carry = (static_cast<uint32_t>(a) & static_cast<uint32_t>(b)) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
// @lc code=end
