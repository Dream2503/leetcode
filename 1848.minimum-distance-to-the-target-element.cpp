/*
 * @lc app=leetcode id=1848 lang=cpp
 *
 * [1848] Minimum Distance to the Target Element
 */

// @lc code=start
class Solution {
public:
    int getMinDistance(const std::vector<int>& nums, const int target, const int start) {
        const int size = nums.size();
        int res = INT_MAX;

        for (int i = 0; i < size; i++) {
            if (nums[i] == target) {
                res = std::min(res, std::abs(i - start));
            }
        }
        return res;
    }
};
// @lc code=end
