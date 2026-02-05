/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

// @lc code=start
class Solution {
public:
    int arraySign(const std::vector<int>& nums) {
        int res = 1;

        for (const int num : nums) {
            if (num < 0) {
                res *= -1;
            } else if (num == 0) {
                return 0;
            }
        }
        return res;
    }
};
// @lc code=end
