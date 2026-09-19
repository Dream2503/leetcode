/*
 * @lc app=leetcode id=4011 lang=cpp
 *
 * [4011] Count Subarrays With Even Odd Ratio I
 */

// @lc code=start
class Solution {
public:
    int countRatioSubarrays(const std::vector<int>& nums, const int a, const int b) {
        const double cutoff = a / static_cast<double>(b);
        int res = 0;
        const int size = nums.size();

        for (int i = 0; i < size; i++) {
            std::pair count = {0.0, 0.0};

            for (int j = i; j < size; j++) {
                (nums[j] % 2 == 0 ? count.first : count.second) += 1;

                if (count.second > 0 && count.first / count.second <= cutoff) {
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
