/*
 * @lc app=leetcode id=1800 lang=cpp
 *
 * [1800] Maximum Ascending Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int maxAscendingSum(const std::vector<int>& nums) {
        const int size = nums.size();
        int res = 0, current = 0;

        for (int i = 0; i < size; i++) {
            current += nums[i];
            res = std::max(res, current);

            if (i < size - 1 && nums[i] >= nums[i + 1]) {
                current = 0;
            }
        }
        return res;
    }
};
// @lc code=end
