/*
 * @lc app=leetcode id=3483 lang=cpp
 *
 * [3483] Unique 3-Digit Even Numbers
 */

// @lc code=start
class Solution {
public:
    int totalNumbers(const std::vector<int>& digits) {
        int res = 0;
        std::array<int, 10> count{};

        for (const int digit : digits) {
            count[digit]++;
        }
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 9; k += 2) {
                    res += count[i] > 0 && count[j] > (i == j) && count[k] > (i == k) + (j == k);
                }
            }
        }
        return res;
    }
};
// @lc code=end
