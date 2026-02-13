/*
 * @lc app=leetcode id=2016 lang=cpp
 *
 * [2016] Maximum Difference Between Increasing Elements
 */

// @lc code=start
class Solution {
public:
    int maximumDifference(const std::vector<int>& nums) {
        const int size = nums.size();
        int res = -1;

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] < nums[j]) {
                    res = std::max(res, nums[j] - nums[i]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
