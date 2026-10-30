/*
 * @lc app=leetcode id=3507 lang=cpp
 *
 * [3507] Minimum Pair Removal to Sort Array I
 */

// @lc code=start
class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        int size = nums.size(), res = 0;

        while (!std::ranges::is_sorted(nums)) {
            int k = -1, min = INT32_MAX;

            for (int i = 0; i < size - 1; i++) {
                if (min > nums[i] + nums[i + 1]) {
                    min = nums[i] + nums[i + 1];
                    k = i;
                }
            }
            nums[k] += nums[k + 1];
            nums.erase(nums.begin() + k + 1);
            size--;
            res++;
        }
        return res;
    }
};
// @lc code=end
