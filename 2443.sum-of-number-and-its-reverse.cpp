/*
 * @lc app=leetcode id=2443 lang=cpp
 *
 * [2443] Sum of Number and Its Reverse
 */

// @lc code=start
class Solution {
    int reverse(int n) {
        int res = 0;

        while (n) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        return res;
    }

public:
    bool sumOfNumberAndReverse(const int num) {
        return std::ranges::any_of(std::views::iota(num / 2, num + 1), [num, this](const int i) -> bool { return i + reverse(i) == num; });
    }
};
// @lc code=end
