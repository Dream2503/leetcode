/*
 * @lc app=leetcode id=1006 lang=cpp
 *
 * [1006] Clumsy Factorial
 */

// @lc code=start
class Solution {
public:
    int clumsy(int n) {
        bool multi = true, first = true;
        int res = 0;

        while (n) {
            if (multi) {
                int temp = n--;

                if (n) {
                    temp *= n--;
                }
                if (n) {
                    temp /= n--;
                }
                res += first ? temp : -temp;
                first = multi = false;
            } else {
                res += n--;
                multi = true;
            }
        }
        return res;
    }
};
// @lc code=end
