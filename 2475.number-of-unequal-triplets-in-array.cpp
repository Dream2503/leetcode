/*
 * @lc app=leetcode id=2475 lang=cpp
 *
 * [2475] Number of Unequal Triplets in Array
 */

// @lc code=start
class Solution {
public:
    int unequalTriplets(const std::vector<int>& nums) {
        const int size = nums.size();
        int res = 0;

        for (int i = 0; i < size - 2; i++) {
            for (int j = i + 1; j < size - 1; j++) {
                for (int k = j + 1; k < size; k++) {
                    res += nums[i] != nums[j] && nums[j] != nums[k] && nums[k] != nums[i];
                }
            }
        }
        return res;
    }
};
// @lc code=end
