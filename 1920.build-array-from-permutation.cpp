/*
 * @lc app=leetcode id=1920 lang=cpp
 *
 * [1920] Build Array from Permutation
 */

// @lc code=start
class Solution {
public:
    std::vector<int> buildArray(const std::vector<int>& nums) {
        const int size = nums.size();
        std::vector res(size, 0);

        for (int i = 0; i < size; i++) {
            res[i] = nums[nums[i]];
        }
        return res;
    }
};
// @lc code=end
