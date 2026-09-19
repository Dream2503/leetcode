/*
 * @lc app=leetcode id=2470 lang=cpp
 *
 * [2470] Number of Subarrays With LCM Equal to K
 */

// @lc code=start
class Solution {
public:
    int subarrayLCM(const std::vector<int>& nums, const int k) {
        int res = 0;
        const int size = nums.size();

        for (int i = 0; i < size; i++) {
            int lcm = 1;

            for (int j = i; j < size; j++) {
                lcm = std::lcm(lcm, nums[j]);

                if (lcm == k) {
                    res++;
                }
                if (lcm > k || k % lcm != 0) {
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
