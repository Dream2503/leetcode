/*
 * @lc app=leetcode id=1945 lang=cpp
 *
 * [1945] Sum of Digits of String After Convert
 */

// @lc code=start
class Solution {
public:
    int getLucky(const std::string s, const int k) {
        int res = 0;

        for (const char ch : s) {
            int i = ch - 'a' + 1;
            res += i / 10 + i % 10;
        }
        for (int i = 1; i < k; i++) {
            int temp = res;
            res = 0;

            while (temp) {
                res += temp % 10;
                temp /= 10;
            }
        }
        return res;
    }
};
// @lc code=end
