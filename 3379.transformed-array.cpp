/*
 * @lc app=leetcode id=3379 lang=cpp
 *
 * [3379] Transformed Array
 */

// @lc code=start
class Solution {
public:
    std::vector<int> constructTransformedArray(const std::vector<int>& nums) {
        const int size = nums.size();
        std::vector<int> res(size);

        for (int i = 0; i < size; i++) {
            res[i] = nums[(i + nums[i] + size * std::abs(nums[i])) % size];
        }
        return res;
    }
};
// @lc code=end
