/*
 * @lc app=leetcode id=2765 lang=cpp
 *
 * [2765] Longest Alternating Subarray
 */

// @lc code=start
class Solution {
public:
    int alternatingSubarray(const std::vector<int>& nums) {
        const int size = nums.size();
        int res = -1, len = 1;

        for (int i = 1; i < size; i++) {
            if (const int diff = nums[i] - nums[i - 1]; diff == (len % 2 == 1 ? 1 : -1)) {
                len++;
            } else {
                len = diff == 1 ? 2 : 1;
            }
            res = std::max(res, len >= 2 ? len : -1);
        }
        return res;
    }
};
// @lc code=end
