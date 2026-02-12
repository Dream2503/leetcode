/*
 * @lc app=leetcode id=1984 lang=cpp
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 */

// @lc code=start
class Solution {
public:
    int minimumDifference(std::vector<int>& nums, const int k) {
        if (k == 1) {
            return 0;
        }
        int res = INT32_MAX;
        const int size = nums.size();
        std::ranges::sort(nums);

        for (int i = 0; i < size - k + 1; i++) {
            res = std::min(res, nums[i + k - 1] - nums[i]);
        }
        return res;
    }
};
// @lc code=end
