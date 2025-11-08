/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
    std::vector<int> grayCode(const int n) {
        std::vector<int> res;
        res.reserve(1 << n);

        for (int i = 0; i < 1 << n; i++) {
            res.push_back(i ^ i >> 1);
        }
        return res;
    }
};
// @lc code=end
