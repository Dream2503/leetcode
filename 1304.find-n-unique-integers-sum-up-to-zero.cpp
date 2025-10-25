/*
 * @lc app=leetcode id=1304 lang=cpp
 *
 * [1304] Find N Unique Integers Sum up to Zero
 */

// @lc code=start
class Solution {
public:
    std::vector<int> sumZero(const int n) {
        std::vector<int> res(n);
        std::iota(res.begin(), res.end() - 1, 1);
        res.back() = -n * (n - 1) / 2;
        return res;
    }
};
// @lc code=end
