/*
 * @lc app=leetcode id=1646 lang=cpp
 *
 * [1646] Get Maximum in Generated Array
 */

// @lc code=start
class Solution {
public:
    int getMaximumGenerated(const int n) {
        if (n == 0) {
            return 0;
        }
        int res = 1;
        std::vector nums(n + 1, 0);
        nums[0] = 0;
        nums[1] = 1;

        for (int i = 1; 2 * i <= n; i++) {
            nums[2 * i] = nums[i];
            res = std::max(res, nums[2 * i]);

            if (2 * i + 1 <= n) {
                nums[2 * i + 1] = nums[i] + nums[i + 1];
                res = std::max(res, nums[2 * i + 1]);
            }
        }
        return res;
    }
};
// @lc code=end
