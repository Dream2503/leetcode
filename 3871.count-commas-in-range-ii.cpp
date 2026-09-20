/*
 * @lc app=leetcode id=3871 lang=cpp
 *
 * [3871] Count Commas in Range II
 */

// @lc code=start
class Solution {
public:
    long long countCommas(const long long n) {
        long long start = 1000, commas = 1, res = 0;

        while (start <= n) {
            const long long end = start > n / 1000 ? n : start * 1000 - 1, count = end - start + 1;
            res += count * commas;
            start *= 1000;
            commas++;
        }
        return res;
    }
};
// @lc code=end
