/*
 * @lc app=leetcode id=1925 lang=cpp
 *
 * [1925] Count Square Sum Triples
 */

// @lc code=start
class Solution {
public:
    int countTriples(const int n) {
        int res = 0;

        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                for (int c = 1; c <= n; c++) {
                    res += a * a + b * b == c * c;
                }
            }
        }
        return res;
    }
};
// @lc code=end
