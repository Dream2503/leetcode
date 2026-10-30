/*
 * @lc app=leetcode id=3848 lang=cpp
 *
 * [3848] Check Digitorial Permutation
 */

// @lc code=start
class Solution {
public:
    bool isDigitorialPermutation(const int n) {
        constexpr static std::array factorials = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        int temp = n, value = 0;

        while (temp) {
            value += factorials[temp % 10];
            temp /= 10;
        }
        std::string lhs = std::to_string(n), rhs = std::to_string(value);
        std::ranges::sort(lhs);
        std::ranges::sort(rhs);
        return lhs == rhs;
    }
};
// @lc code=end
