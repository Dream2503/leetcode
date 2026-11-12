/*
 * @lc app=leetcode id=3105 lang=cpp
 *
 * [3105] Longest Strictly Increasing or Strictly Decreasing Subarray
 */

// @lc code=start
class Solution {
public:
    int longestMonotonicSubarray(const std::vector<int>& nums) {
        const int size = nums.size();
        int res = 0;

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j <= size; j++) {
                bool increasing = true, decreasing = true;

                for (int k = i + 1; k < j; k++) {
                    if (nums[k - 1] >= nums[k]) {
                        increasing = false;
                    }
                    if (nums[k - 1] <= nums[k]) {
                        decreasing = false;
                    }
                }
                if (increasing || decreasing) {
                    res = std::max(res, j - i);
                }
            }
        }
        return res;
    }
};
// @lc code=end
