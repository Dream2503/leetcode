/*
 * @lc app=leetcode id=1317 lang=cpp
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 */

// @lc code=start
class Solution {
    int index_zero(int n) {
        int i = 0;

        while (n) {
            if (n % 10 == 0) {
                return i;
            }
            n /= 10;
            i++;
        }
        return -1;
    }

public:
    std::vector<int> getNoZeroIntegers(const int n) {
        std::vector res = {1, n - 1};

        while (true) {
            const int factor = std::max(index_zero(res[0]), index_zero(res[1]));

            if (factor == -1) {
                return res;
            }
            res[0] += std::pow(10, factor) + 1;
            res[1] -= std::pow(10, factor) + 1;
        }
    }
};
// @lc code=end
