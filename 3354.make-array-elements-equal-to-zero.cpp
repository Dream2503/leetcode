/*
 * @lc app=leetcode id=3354 lang=cpp
 *
 * [3354] Make Array Elements Equal to Zero
 */

// @lc code=start
class Solution {
public:
    int countValidSelections(const std::vector<int>& nums) {
        const int size = nums.size();
        int left = 0, right = std::reduce(nums.begin(), nums.end(), 0), res = 0;

        for (int i = 0; i < size; i++) {
            if (!nums[i]) {
                if (left == right) {
                    res += 2;
                } else if (std::abs(left - right) == 1) {
                    res++;
                }
            } else {
                left += nums[i];
                right -= nums[i];
            }
        }
        return res;
    }
};
// @lc code=end
