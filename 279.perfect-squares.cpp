/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
    bool is_square(const int n) {
        const int res = std::sqrt(n);
        return res * res == n;
    }

public:
    int numSquares(int n) {
        if (is_square(n)) {
            return 1;
        }
        const int start = n;

        while (n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 == 7) {
            return 4;
        }
        for (int i = 1; i * i <= start; i++) {
            if (is_square(start - i * i)) {
                return 2;
            }
        }
        return 3;
    }
};
// @lc code=end
