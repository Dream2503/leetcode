/*
 * @lc app=leetcode id=1486 lang=cpp
 *
 * [1486] XOR Operation in an Array
 */

// @lc code=start
class Solution {
public:
    int xorOperation(const int n, const int start) {
        int res = start;

        for (int i = 1; i < n; i++) {
            res ^= start + 2 * i;
        }
        return res;
    }
};
// @lc code=end

