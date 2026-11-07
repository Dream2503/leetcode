/*
 * @lc app=leetcode id=3270 lang=cpp
 *
 * [3270] Find the Key of the Numbers
 */

// @lc code=start
class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int res = 0, multiplier = 1;

        for (int i = 0; i < 4; ++i) {
            res += std::min({num1 % 10, num2 % 10, num3 % 10}) * multiplier;
            multiplier *= 10;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }
        return res;
    }
};
// @lc code=end
