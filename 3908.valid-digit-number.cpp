/*
 * @lc app=leetcode id=3908 lang=cpp
 *
 * [3908] Valid Digit Number
 */

// @lc code=start
class Solution {
public:
    bool validDigit(int n, const int x) {
        bool res = false;

        while (n > 9) {
            if (n % 10 == x) {
                res = true;
            }
            n /= 10;
        }
        return n != x && res;
    }
};
// @lc code=end
