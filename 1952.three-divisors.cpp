/*
 * @lc app=leetcode id=1952 lang=cpp
 *
 * [1952] Three Divisors
 */

// @lc code=start
class Solution {
public:
    bool isThree(const int n) {
        bool found = false;

        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                if (found) {
                    return false;
                }
                found = true;
            }
        }
        return found;
    }
};
// @lc code=end
