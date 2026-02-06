/*
 * @lc app=leetcode id=1909 lang=cpp
 *
 * [1909] Remove One Element to Make the Array Strictly Increasing
 */

// @lc code=start
class Solution {
public:
    bool canBeIncreasing(std::vector<int>& nums) {
        const int size = nums.size();
        bool removed = false;

        for (int i = 1; i < size; i++) {
            if (nums[i] <= nums[i - 1]) {
                if (removed) {
                    return false;
                }
                if (i > 1 && nums[i] <= nums[i - 2]) {
                    nums[i] = nums[i - 1];
                }
                removed = true;
            }
        }
        return true;
    }
};
// @lc code=end
