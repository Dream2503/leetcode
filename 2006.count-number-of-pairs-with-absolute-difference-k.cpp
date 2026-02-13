/*
 * @lc app=leetcode id=2006 lang=cpp
 *
 * [2006] Count Number of Pairs With Absolute Difference K
 */

// @lc code=start
class Solution {
public:
    int countKDifference(const vector<int>& nums, const int k) {
        const int size = nums.size();
        int res = 0;

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                res += std::abs(nums[i] - nums[j]) == k;
            }
        }
        return res;
    }
};
// @lc code=end
